class Solution {
public:
    int check(vector<int> nums, int divisor, int threshold)
    {
        int n = nums.size();
        long long int sum = 0;
        for(int i = 0; i < n; i++)
            sum += (nums[i] + divisor -1 ) / divisor;
        return sum <= threshold ? 1 : 0;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(check(nums, mid, threshold) == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};