class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        queue<pair<int, int>> qu;
        dist[0][0] = 1;
        qu.push({0, 0});
        while(!qu.empty()){
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            for(int z = 0; z < 8; z++){
                int x_new = x + dx[z];
                int y_new = y + dy[z];
                if(x_new < 0 || x_new >= n || y_new < 0 || y_new >= n || grid[x_new][y_new] == 1)   continue;
                else if(dist[x][y] + 1 < dist[x_new][y_new]){
                    dist[x_new][y_new] = dist[x][y] + 1;
                    qu.push({x_new, y_new});
                }
            }
        }
        if(dist[n - 1][n - 1] == INT_MAX)   return -1;
        return dist[n - 1][n - 1];
    }
};