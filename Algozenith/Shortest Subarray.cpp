#include<bits/stdc++.h>
using namespace std;
#define int long long int
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
        unordered_map<int, int> dist_map;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            dist_map[v[i]]++;
        }
        int i = 0, j = 0, c = 0;
        int len = LLONG_MAX;
        int d = dist_map.size();    //number of distinct elements
        unordered_map<int, int> mp;
        while(j < n && i < n)
        {
            if(mp.find(v[j]) == mp.end())   c++;
            mp[v[j]]++;
            while(c == d && mp[v[i]] > 1)
            {
                mp[v[i]]--;
                i++;
            }
            if(c == d)  len = min(len, j - i + 1);
            j++;
        }
        cout << len << "\n";
    }
    return 0;
}