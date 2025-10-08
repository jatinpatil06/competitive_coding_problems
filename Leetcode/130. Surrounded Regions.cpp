class Solution {
public:
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'X' || visited[i][j]) return;
        visited[i][j] = 1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int z = 0; z < 4; z++)
            dfs(grid, visited, i + dx[z], j + dy[z]);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')  dfs(board, visited, i, j);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(visited[i][j] != 1)  board[i][j] = 'X';
    }
};