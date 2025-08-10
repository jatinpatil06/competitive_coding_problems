#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int l = 0, r = 0, c = 0;
        unordered_map<int, int> mp;
        int no_of_subarrays = 0;
        while(r < n)
        {
            mp[v[r]]++;
            if(mp[v[r]] == 1)   c++;
            while(c > k)
            {
                mp[v[l]]--;
                if(mp[v[l]] == 0)   c--;
                l++;
            }
            no_of_subarrays += r - l + 1;
            r++;
        }
        cout << no_of_subarrays << "\n";
    }
    return 0;
}