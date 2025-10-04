class Solution {
public:
    int atMost(vector<int> &nums, int k){
        if(k < 0)   return 0;
        int l = 0, r = 0, s = 0, n = nums.size(), no_of_subarrays = 0;
        while(r < n){
            s += nums[r];
            while(s > k)    s -= nums[l++];
            no_of_subarrays += r - l + 1;
            r++;
        }
        return no_of_subarrays;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};