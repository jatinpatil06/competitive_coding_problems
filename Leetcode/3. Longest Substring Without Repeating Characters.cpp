class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        Brute Force Approach TC = O(N ^ 2)
        int max_len = 0, n = s.length();
        for(int i = 0; i < n; i++){
            unordered_map<char, int> mp;
            for(int j = i; j < n; j++){
                if(mp[s[j]] == 1)   break;
                mp[s[j]]++;
                max_len = max(max_len, j - i + 1);
            }
        }
        return max_len;

        An optimal apporach would be to use two pointers
        */
        int l = 0, r = 0, n = s.length(), max_len = 0;
        unordered_map<char, int> mp;
        while(r < n){
            mp[s[r]]++;
            while(mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};