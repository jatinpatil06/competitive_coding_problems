#include<bits/stdc++.h>
using namespace std;
#define int long long int
int check(int v[], int mid, int k, int n)
{
    int no_of_painters = 0;
    int last_painter_remaining = 0;
    for(int i = 0; i < n; i++)
    {
        
        if(v[i] > last_painter_remaining)
        {
            no_of_painters++;
            last_painter_remaining = mid;
        }
        last_painter_remaining -= v[i];
    }
    return no_of_painters <= k;
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
        int boards[n];
        int max_element = 0;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> boards[i];
            max_element = max(max_element, boards[i]);
            sum += boards[i];
        }

        //binary searching on the answer
        int low = max_element, high = sum;
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + (high - low) / 2);
            if(check(boards, mid, k, n) == 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}