class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l = 0, r = 0, max_len = 0, n = s.size();
       map <char, int> mp;
       while(r < n)
       {
            if(mp.find(s[r]) != mp.end())
                l = max(l, mp[s[r]] + 1);
            mp[s[r]] = r;
            max_len = max(max_len, r - l + 1);
            r++;
       } 
       return max_len;
    }
};