class Solution {
public:
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>> &image, int i, int j, int color, int initial)
    {
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == color || image[i][j] != initial)
            return;
        image[i][j] = color;
        for(int z = 0; z < 4; z++)
            dfs(image, i + x[z], j + y[z], color, initial);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] != color)
            dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};