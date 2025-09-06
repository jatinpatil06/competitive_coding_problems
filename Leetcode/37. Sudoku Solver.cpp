class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char val){
        int min_row = row / 3;
        min_row *= 3;
        int min_col = col / 3;
        min_col *= 3;
        //checking that grid
        for(int i = min_row; i < min_row + 3; i++)
            for(int j = min_col; j < min_col + 3; j++)
                if(board[i][j] == val)  return false;
        //checking particular row
        for(int j = 0; j < 9; j++)  if(board[row][j] == val)    return false;
        //checking particular column
        for(int i = 0; i < 9; i++)  if(board[i][col] == val)    return false; 
        return true;
    }

    bool rec(vector<vector<char>>& board, int row, int col)
    {
        if(row >= 9)    return true;
        else if(col >= 9)   return rec(board, row + 1, 0);
        else if (board[row][col] != '.')    return rec(board, row, col + 1);
        else 
        {
            for(char ch = '1'; ch <= '9'; ch++)
            {
                if(check(board, row, col, ch))
                {
                    board[row][col] = ch;
                    if(rec(board, row, col + 1))    return true;
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        rec(board, 0, 0);
    }
};