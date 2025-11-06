class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        /*
        Brute Force Solution TC = O(N ^ 2)
        int max_subarr = -1, n = s.length();
        for(int i = 0; i < n; i++){
            unordered_map<char, int> mp;
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                if(mp.size() == k)   max_subarr = max(max_subarr, j - i + 1);
            }
        }
        return max_subarr;
        
        Optimal Approach would be to use two pointers
        */
        int max_subarr = -1, n = s.length();
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        
        for(r = 0; r < n; r++){
            mp[s[r]]++;
            while(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0)   mp.erase(s[l]);
                l++;
            }
            if(mp.size() == k)  max_subarr = max(max_subarr, r - l + 1);
        }
        return max_subarr;
    }
};