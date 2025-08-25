class Solution {
public:
    int atMost(string s, char ch, int k)
    {
        int l = 0, r = 0, c = 0, n = s.size(), subarrs = 0;
        while(r < n)
        {
            if(s[r] == ch)  c++;
            while(c > k)
                if(s[l++] == ch)    c--;
            if(l <= r)  subarrs += r - l + 1;
            r++;
        }
        return subarrs;
    }
    int uniqueLetterString(string s) {
        int uniques = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++)
            uniques += atMost(s, ch, 1) - atMost(s, ch, 0);
        return uniques;
    }
};