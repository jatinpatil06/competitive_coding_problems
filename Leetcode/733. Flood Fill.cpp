class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int colour, int initial_colour){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != initial_colour)   return;
        grid[i][j] = colour;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int z = 0; z < 4; z++)
            dfs(grid, i + dx[z], j + dy[z], colour, initial_colour);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)  dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};