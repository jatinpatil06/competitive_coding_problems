#include<bits/stdc++.h>
using namespace std;
int n;
vector<char> v;
void parenthesis(int idx, int i)
{
    if(i < 0 || idx > n)   return;
    if(idx == n && i == 0)
    {
        for(int j =0; j < n; j++)   cout << v[j];
        cout << "\n";
    }
    else
    {
        v[idx] = '(';
        parenthesis(idx + 1, i + 1);
        v[idx] = ')';
        parenthesis(idx + 1, i - 1);
    }
}
int main()
{
    cin >> n;
    v.resize(n);
    parenthesis(0, 0);
    return 0;
}