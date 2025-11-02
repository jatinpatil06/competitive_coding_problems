class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, sum = 0;
        unordered_map<int, int> prefix_map;
        prefix_map[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            //check whether any prefix sums exist till now which can be subtracted from the current prefix sum to get a subarray with sum = k
            if(prefix_map.find(sum - k) != prefix_map.end())   count += prefix_map[sum - k];
            prefix_map[sum] += 1;
        }
        return count;
    }
};