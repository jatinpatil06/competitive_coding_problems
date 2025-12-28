class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        /*  Brute Force TC = O(N^2)
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum == k)    count++;
            }
        }
            An optimal approach would be to use prefix sums TC = O(N)
        */
        int sum = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end())    count += mp[sum - k];
            mp[sum] += 1;
        }
        return count;
    }
};