#include<bits/stdc++.h>
#define int long long
using namespace std;
bool check(int n, int s, int mid)
{
    int sum = 0, mid_cpy = mid;
    while(mid_cpy > 0)
    {
        int r = mid_cpy % 10;
        sum += r;
        mid_cpy /= 10;
    }
    return mid - sum >= s ? true : false;
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
        int n, s;
        cin >> n >> s;
        int low = 1, high = n, answer = 0;
        while(low <= high)
        {
            int mid = (high - low) / 2 + low;
            if(check(n, s, mid))
            {
                answer = n - mid + 1;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        cout << answer << "\n";
    }
    return 0;
}