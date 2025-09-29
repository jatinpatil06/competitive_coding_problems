class Solution {
public:
    int cost(vector<vector<int>> &grid, int i, int j)
    {
        if(i < 0 || j < 0)  return 0;
        if(grid[i][j] != -1)    return grid[i][j];
        return grid[i][j] = cost(grid, i - 1, j) + cost(grid, i, j - 1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        grid[0][0] = 1;
        return cost(grid, m - 1, n - 1);
    }
};