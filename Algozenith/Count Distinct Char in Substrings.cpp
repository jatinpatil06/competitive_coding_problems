#include<bits/stdc++.h>
using namespace std;
#define int long long int
int each_char_contrib(string s, char ch)
{
    int l = 0, r = 0, count = 0, n = s.size();
    //finding the number of substrings which do not contain ch
    bool flag = false;
    while(r < n)
    {
        if(s[r] == ch)  flag = true;
        while(flag == true)
            if(s[l++] == ch)    flag = false;
        if(l <= r)  count += r - l + 1;
        r++;
    }
    return (n * (n + 1)) / 2 - count;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int score = 0;
        for(char ch = 'a'; ch <= 'z'; ch++)
            score += each_char_contrib(s, ch);
        cout << score << "\n";
    }
    return 0;
}