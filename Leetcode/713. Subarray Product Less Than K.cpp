class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)  return 0;
        int l = 0, r = 0, n = nums.size();
        int count = 0;
        long long int product = 1;
        while(r < n)
        {
            product *= nums[r];
            while(product >= k)
            {
                product /= nums[l];
                l++;
            }
            if(product < k) count += r - l + 1;
            r++;
        }
        return count;
    }
};