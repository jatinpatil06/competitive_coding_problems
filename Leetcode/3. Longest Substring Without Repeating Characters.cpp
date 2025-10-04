class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int l = 0, r = 0, max_len = 0;
        map<int, int> mp;
        while(r < s.length()){
            mp[s[r]]++;
            while(mp[s[r]] > 1) mp[s[l++]]--;
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};