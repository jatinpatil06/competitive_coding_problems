#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int max_len = 0;
        while(j < v.size())
        {
           mp[v[j]]++;
           while(mp[v[j]] > 1)
           {
                mp[v[i]]--;
                i++;
           }
           max_len = max(max_len, j - i + 1);
           j++;
        }
            cout << max_len << "\n";
    }
    return 0;
}