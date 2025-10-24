class Solution {
public:
    bool isValid(vector<vector<int>> &grid, int x, int y){
        int m = grid.size(), n = grid[0].size();
        if(x >= 0 && x < m  && y >= 0 && y < n && grid[x][y] == 1)    return true;
        return false;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int replacement){
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        grid[i][j] = replacement;
        for(int z = 0; z < 4; z++){
            int x = i + dx[z];
            int y = j + dy[z];
            if(isValid(grid, x, y)) dfs(grid, x, y, replacement);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int enclave_land = 0;
        //clearing out the border regions first
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 1)   dfs(grid, i, j, -1);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) dfs(grid, i, j, 2);
                if(grid[i][j] == 2) enclave_land++;
            }
        }
        return enclave_land;
    }
};