class Solution {
public:
    long long each_char_contribution(string s, char ch)
    {
        long long l = 0, r = 0, count = 0, n = s.size();
        bool flag = false;
        while(r < n)
        {
            if(s[r] == ch) flag = true;
            while(flag == true)
                if(s[l++] == ch)    flag = false;
            if(l <= r)  count += r - l + 1;
            r++;
        }
        return (n * (n + 1)) / 2 - count;
    }
    long long appealSum(string s) {
        long long appeal = 0;
        for(char ch = 'a'; ch <= 'z'; ch++)
            appeal += each_char_contribution(s, ch);
        return appeal;
    }
};