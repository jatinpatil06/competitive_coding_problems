#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool check(vector<int> v, int k, int mid)
{
    int points_placed = 0;
    for(int i = 1; i < v.size(); i++)
        points_placed += (v[i] - v[i - 1] - 1) / mid;
    return points_placed <= k ? true : false;
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
        int n, k;
        cin >> n >> k;
        vector<int> v (n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int min_gap = 1, max_gap = LLONG_MIN;
        for(int i = 1; i < n; i++)
        {
            min_gap = min(min_gap, v[i] - v[i - 1]);
            max_gap = max(max_gap, v[i] - v[i - 1]);
        }
        int answer = 0;
        while(min_gap <= max_gap)
        {
            int mid = (max_gap - min_gap) / 2 + min_gap;
            if(check(v, k, mid))
            {
                answer = mid;
                max_gap = mid - 1;
            }
            else    min_gap = mid + 1;
        }
        cout << answer << "\n";
    }
    return 0;
}