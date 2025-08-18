class Solution {
public:
    string check(string s, int l, int r){
        string longest = "";
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            longest = s.substr(l, r - l + 1);
            l--;
            r++;
        }
        return longest;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string longest = "";
        for(int i = 0; i < n; i++)
        {
            string temp = check(s, i, i);
            if(temp.length() > longest.length())   longest = temp;
            temp = check(s, i , i + 1);
            if(temp.length() > longest.length())   longest = temp;
        }
        return longest;
    }
};