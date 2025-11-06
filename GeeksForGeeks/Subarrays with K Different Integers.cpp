class Solution {
public:
    int atMost(vector<int> &nums, int k){
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mp;
        for(; r < nums.size(); r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)    mp.erase(nums[l]);
                l++;
            }
            if(mp.size() <= k)  count += r - l + 1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        /*
        Brute Force TC = O(N ^ 2)
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> mp;
            for(int j = i; j < n; j++){
                mp[nums[j]]++;
                if(mp.size() == k)  count++;
            }
        }
        return count;

        An Optimal approach would be to use 2 pointers, find atMost(k) - atMost(k - 1)
        */
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};