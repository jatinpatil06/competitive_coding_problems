#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isPalindrome(string s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])    return false;
        i++;
        j--;
    }
    return true;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int i = 0, j = s.size() - 1;
        bool ok = true;
        while(i <= j)
        {
            if(s[i] != s[j])
            {
                ok = isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
                break;
            }
            i++;
            j--;
        }
        if(ok)  cout << "Y\n";
        else    cout << "N\n";
    }
    return 0;
}