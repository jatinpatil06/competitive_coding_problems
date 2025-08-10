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
        int n, d;
        cin >> n >> d;
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        int penalty = LLONG_MAX;
        int i = 0, j = 0;
        int count = 0;
        unordered_map<int, int> mp;
        for(; j < d; j++)
        {
            if(mp[nums[j]] == 0)    count++;
            mp[nums[j]] += 1;
        }
        penalty = min(penalty, count);
        for(;j < n; j++)
        {
            if(mp[nums[i]] == 1)    count--;
            mp[nums[i]] -= 1;
            i++;
            if(mp[nums[j]] == 0)    count++;
            mp[nums[j]] += 1;
            penalty = min(penalty, count);
        }
        cout << penalty << "\n";
    }
    return 0;
}