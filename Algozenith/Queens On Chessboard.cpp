#include<bits/stdc++.h>
using namespace std;
vector<int> queens(8);
vector<vector<char>> grid(8, vector<char>(8));

bool check(int row, int col)
{
    for(int pr = 0; pr < row; pr++)
    {
        int pc = queens[pr];
        if((pc == col) || (abs(pc - col) == abs(pr - row))) return false;
    }
    return true;
}

int rec(int level)
{
    int n = 8;
    if(level == n)  return 1;
    else
    {
        int ans = 0;
        for(int col = 0; col < n; col++)
        {
            if(grid[level][col] == '.' && check(level, col))
            {
                queens[level] = col;
                ans += rec(level + 1);
                queens[level] = -1;
            }
        }
        return ans;
    }
}

int main()
{
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> grid[i][j];
    cout << rec(0);
    return 0;
}