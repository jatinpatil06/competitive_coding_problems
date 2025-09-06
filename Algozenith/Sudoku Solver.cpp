#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> board(9, vector<char>(9));
bool check(int row, int col, char val)
{
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for(int i = sr; i < sr + 3; i++)
        for(int j = sc; j < sc + 3; j++)
            if(board[i][j] == val)  return false;
    for(int i = 0; i < 9; i++)
        if(board[row][i] == val || board[i][col] == val)    return false;
    return true;
}

bool rec(int row, int col)
{
    if(row >= 9)    return true;
    else if(col >= 9)   return rec(row + 1, 0);
    else if(board[row][col] != '.') return rec(row, col + 1);
    else
    {
        for(char ch = '1'; ch <= '9'; ch++)
        {
            if(check(row, col, ch))
            {
                board[row][col] = ch;
                if(rec(row, col + 1))return true;
                board[row][col] = '.';
            }
        }
    }
    return false;
}
int main()
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            cin >> board[i][j];
    rec(0, 0);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << board[i][j];
        cout << "\n";
    }
    return 0;
}