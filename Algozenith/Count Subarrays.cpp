#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int l = 0, r = 0;
        int num = 0;
        num++;
        r++;
        while(r < n)
        {
            if(v[r] >= v[r - 1]) num += r - l + 1;
            else
            {
                l = r;
                num++;
            }
            r++;
        }
        cout << num << "\n";
    }
    return 0;
}