class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        //now we will do dfs on all the 4 adjacent neighbours
        for(int z = 0; z < 4; z++)
            dfs(grid, i + x[z], j + y[z]);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    count += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};