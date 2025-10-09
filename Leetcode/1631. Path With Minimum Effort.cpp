class Solution {
public:
    int is_valid(int x, int y, int n, int m){
        if(x < 0 || x >= n || y < 0 || y >= m)  return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> effort_mat(n, vector<int> (m, INT_MAX));
        effort_mat[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater <pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int currentEffort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for(int z = 0; z < 4; z++){
                int new_x = x + dx[z];
                int new_y = y + dy[z];
                if(is_valid(new_x, new_y, n, m)){
                    int newEffort = max(currentEffort, abs(heights[x][y] - heights[new_x][new_y]));
                    if(newEffort < effort_mat[new_x][new_y]){
                        pq.push({newEffort, {new_x, new_y}});
                        effort_mat[new_x][new_y] = newEffort;
                    }
                }
            }
        }
        return effort_mat[n - 1][m - 1];
    }
};