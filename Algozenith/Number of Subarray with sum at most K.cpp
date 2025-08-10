#include<bits/stdc++.h>
#define int long long int
using namespace std;
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
        int cur_sum = 0, l = 0, r = 0;
        int no_of_subarr = 0;
        while(r < n)
        {
            cur_sum += v[r];
            while(cur_sum > k)
                cur_sum -= v[l++];
            no_of_subarr += r - l + 1;
            r++;
        }
        cout << no_of_subarr << "\n";
    }
    return 0;
}