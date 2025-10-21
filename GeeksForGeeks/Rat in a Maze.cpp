class Solution {
  public:
    void traverse(vector<vector<int>>& maze, int i, int j, string current_path, vector<string> &paths){
        int m = maze.size(), n = maze[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || maze[i][j] == 0)   return;
        if(i == (m - 1) && j == (n - 1))    paths.push_back(current_path);
        else{
            maze[i][j] = 0;
            int dx[4] = {1, 0, 0, -1};
            int dy[4] = {0, -1, 1, 0};
            char direction[4] = {'D', 'L', 'R', 'U'};
            for(int z = 0; z < 4; z++){
                int x = i + dx[z], y = j + dy[z];
                char dir = direction[z];
                traverse(maze, x, y, current_path + dir, paths);
            }
            maze[i][j] = 1;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> paths;
        traverse(maze, 0, 0, "", paths);
        return paths;
    }
};