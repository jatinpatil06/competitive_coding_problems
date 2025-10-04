class Solution {
public:
    int atMost(vector<int> &nums, int k){
        int l = 0, r = 0, n = nums.size(), no_of_subarrays = 0;
        unordered_map<int, int> mp;
        while(r < n){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)    mp.erase(nums[l]);
                l++;
            }
            no_of_subarrays += r - l + 1;
            r++;
        }
        return no_of_subarrays;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};