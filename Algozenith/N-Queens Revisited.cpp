#include<bits/stdc++.h>
using namespace std;
vector<int> queens(14);
int x[8] = {-1, -2, -2, -1, 1, 2, 1, 2};
int y[8] = {-2, -1, 1, 2, 2, 1, -2, -1};
bool check(int row, int col, int n)
{
    for(int pr = 0; pr < row; pr++)
    {
        int pc = queens[pr];
        if((col == pc) || (abs(col - pc) == abs(row - pr))) return false;
        for(int i = 0; i < 8; i++)
        {
            int dx = row + x[i];
            int dy = col + y[i];
            if(dx >= 0 && dx < n && dy >= 0 && dy < n)
            if((pr == dx) && (pc == dy))    return false;
        }
    }
    return true;
}

int rec(int level, int n)
{
    if(level == n)  return 1;
    else
    {
        int ans = 0;
        for(int col = 0; col < n; col++)
        {
            if(check(level, col, n))
            {
                queens[level] = col;
                ans += rec(level + 1, n);
                queens[level] = -1;
            }
        }
        return ans;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << rec(0, n);
    return 0;
}