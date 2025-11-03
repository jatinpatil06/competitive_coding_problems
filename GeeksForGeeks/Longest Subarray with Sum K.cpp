class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix_sum(n);
        prefix_sum[0] = arr[0];
        unordered_map<int, int> mp;
        mp[prefix_sum[0]] = 0;
        for(int i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
            if(mp.find(prefix_sum[i]) == mp.end())
                mp[prefix_sum[i]] = i;
        }  
        int longest = 0;
        for(int i = 0; i < n; i++){
            if(prefix_sum[i] == k)  longest = max(longest, i + 1);
            else if(mp.find(prefix_sum[i] - k) != mp.end())   longest = max(longest, i - mp[prefix_sum[i] - k]);
        }
        return longest;
    }
};