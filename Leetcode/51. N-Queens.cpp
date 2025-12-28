class Solution {
public:
    bool isValid(vector<string> &grid, int row, int col, int n){
        for(int i = 0; i < row; i++)  if(grid[i][col] == 'Q') return false;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < n; j++){
                if(abs(row - i) == abs(col - j) && (grid[i][j] == 'Q')) return false;
            }
        }
        return true;
    }
    void solveNQueens(vector<string> &grid, int row, int n, vector<vector<string>> &answers){
        if(row == n)    answers.push_back(grid);
        else{
            for(int col = 0; col < n; col++){
                if(isValid(grid, row, col, n)){
                    grid[row][col] = 'Q';
                    solveNQueens(grid, row + 1, n, answers);
                    grid[row][col] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> answers;
        solveNQueens(grid, 0, n, answers);
        return answers;
    }
};