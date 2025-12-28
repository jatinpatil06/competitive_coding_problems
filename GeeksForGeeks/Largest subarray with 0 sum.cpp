class Solution {
  public:
    int maxLength(vector<int>& arr) {
        /*  Brute Force approach with TC = O(N ^ 2)
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    sum += arr[j];
                    if(sum == 0)    max_subarr_len = max(j - i, max_subarr_len);
                }
            }
            return max_subarr_len;
            An optimal approach would be to use prefix sums, 
            any current prefix sum, if equal to another previous prefix sum 
            indicates that there lies a zero sum subarray between those two 
            This approach has TC = O(N) & SC = O(N)
        */
        int max_subarr_len = 0, sum = 0, n = arr.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(mp.find(sum) != mp.end())  max_subarr_len = max(i - mp[sum], max_subarr_len);
            else    mp[sum] = i;
        }
        return max_subarr_len;
    }
};