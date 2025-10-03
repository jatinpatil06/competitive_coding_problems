class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        Brute Force Solution
        int n = nums.size();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(nums[i] + nums[j] == target) return {i, j};
        return {-1, -1};
        */
        //An optimized approach would be to use a hash map
        unordered_map<int, int> mp;
        //single pass to calculate the frequencies
        for(int i = 0; i < nums.size(); i++)    mp[nums[i]] = i;
        //now we will try to find the complement for each element
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(mp[complement] != 0 && i != mp[complement])  return {i, mp[complement]};
        }
        return {-1, -1};
    }
};