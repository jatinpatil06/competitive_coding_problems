#include<bits/stdc++.h>
using namespace std;
#define int long long
int atMost(string s, char ch, int k)
{
    int l = 0, r = 0, c = 0, subarrays = 0, n = s.size();
    while(r < n)
    {
        if(s[r] == ch)  c++;
        while(c > k)
            if(s[l++] == ch)    c--;
        if(l <= r)  subarrays += r - l + 1;
        r++;
    }
    return subarrays;
}

void solve()
{
    int n, score = 0;
    string s;
    cin >> n >> s;
    for(char ch = 'a'; ch <= 'z'; ch++)
        score += atMost(s, ch, 1) - atMost(s, ch, 0);
    cout << score << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}