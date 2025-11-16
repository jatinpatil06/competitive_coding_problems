class Solution {
public:
    bool check(int maxSum, int maxSubarrs, vector<int> &arr){
        int subarrs = 0, sumLeft = 0;
        for(int i = 0; i < arr.size(); i++){
            if(sumLeft - arr[i] < 0){
                subarrs++;
                sumLeft = maxSum;
            }
            sumLeft -= arr[i];
        }
        return subarrs <= maxSubarrs ? true : false;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN, high = 0;
        for(int i = 0; i < nums.size(); i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        /*  Brute Force approach
        for(; low <= high; low++){
            if(check(low, k, nums)) return low;
        }
            An optimal approach would be to use binary search on answer
        */
        int ans = -1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(check(mid, k, nums)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};