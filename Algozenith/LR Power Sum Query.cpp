#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

int mod_inverse(int);
int bin_pow(int base, int exp)
{
    base %= MOD;
    if(exp < 0)    return mod_inverse(bin_pow(base, -exp));
    int result = 1;
    while(exp > 0)
    {
        if(exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int mod_inverse(int a)
{
    return bin_pow(a, MOD - 2);
}

signed main()
{
    int n, q , k;
    cin >> n >> q >> k;
    vector<int> A(n + 1, 0), B(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if(A[i] < 0)    A[i] = (A[i] + MOD) % MOD;
    }
    for(int i = 1; i <= n; i++)
        B[i] = (B[i - 1] + (A[i] * bin_pow(k, i - 1)) % MOD) % MOD;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int weightedRange = B[r] - B[l - 1];
        int multiplicantConst = bin_pow(k, - (l - 1));
        cout << ((weightedRange + MOD) % MOD * multiplicantConst % MOD) % MOD  << "\n";
    }
    return 0;
}