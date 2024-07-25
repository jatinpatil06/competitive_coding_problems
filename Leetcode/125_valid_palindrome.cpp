class Solution {
public:
    bool isPalindrome(string s) {
        string cleared;
        for(auto i = s.begin(); i != s.end(); i++)
        {
            if(isalnum(*i) != 0)
                cleared += (char)tolower(*i);
        }
        string s2 = cleared;
        reverse(s2.begin(), s2.end());
        if(s2 == cleared)
            return true;
        return false;
    }
};