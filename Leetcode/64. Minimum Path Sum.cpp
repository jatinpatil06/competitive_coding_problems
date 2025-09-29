class Solution {
public:
    int cost(vector<vector<int>> &grid, vector<vector<int>> &costGrid, int i, int j)
    {
        if(i < 0 || j < 0)  return INT_MAX;
        if(costGrid[i][j] != -1)    return costGrid[i][j];
        return costGrid[i][j] = min(cost(grid, costGrid, i - 1, j), cost(grid, costGrid, i, j - 1)) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> costGrid(m, vector<int> (n, -1));
        costGrid[0][0] = grid[0][0];
        return cost(grid, costGrid, m - 1, n - 1);
    }
};