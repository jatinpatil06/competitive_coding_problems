#include<bits/stdc++.h>
#define int long long
using namespace std;
int check_no_of_subarrs(vector<int> v, int mid)
{
    int count = 0;
    int l = 0, r = 0, sum = 0;
    while(r < v.size())
    {
        sum += v[r];
        while(sum > mid)
            sum -= v[l++];
        r++;
        count += r - l;
    }
    return count;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int low = 0, high = 0, m = (n * (n + 1)) / 2;  
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            high += v[i];
        }
        int answer = 0;
        while(low <= high)
        {
            int mid = (high - low) / 2 + low;
            int subarrs = check_no_of_subarrs(v, mid);
            if(subarrs >= ((m + 1)/ 2))
            {
                answer = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        cout << answer << "\n";
    }
    return 0;
}