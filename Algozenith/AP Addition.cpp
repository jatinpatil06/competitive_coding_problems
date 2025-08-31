#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
signed main()
{
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 2), B(n + 2), C(n + 1);
    while(q--)
    {
        int a, d, l, r;
        cin >> a >> d >> l >> r;
        A[l] += a - l * d;
        B[l] += d;
        A[r + 1] -= (a - l * d);
        B[r + 1] -= d;
    }
    for(int i = 1; i <= n; i++)
    {
        A[i] += A[i - 1];
        B[i] += B[i - 1];
    }
    for(int i = 1; i <= n; i++)
        C[i] = (A[i] % MOD + (i * B[i]) % MOD + MOD) % MOD;
    for(int i = 1; i <= n; i++)
        cout << C[i] << " ";
    return 0;
}