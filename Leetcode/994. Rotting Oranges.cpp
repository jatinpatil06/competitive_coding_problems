#define fresh 1
#define rotten 2
class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int x, int y){
        int m = grid.size(), n = grid[0].size();
        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == fresh)   return true;
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>   qu;
        int fresh_oranges = 0;
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == fresh) fresh_oranges++;
                if(grid[i][j] == rotten)    qu.push({i, j}); 
            }
        }
        if(fresh_oranges == 0 && qu.size() == 0)    return 0;
        int minutes_elapsed = 0;
        while(!qu.empty()){
            int curr_rotten_oranges = qu.size();
            for(int i = 0; i< curr_rotten_oranges; i++){
                pair<int, int> curr_coord = qu.front();
                qu.pop();
                for(int z = 0; z < 4; z++){
                    int x = curr_coord.first + dx[z];
                    int y = curr_coord.second + dy[z];
                    if(isValid(grid, x, y)){
                        fresh_oranges--;
                        grid[x][y] = rotten;
                        qu.push({x, y});
                    }
                }
            }
            minutes_elapsed++;
        }
        return fresh_oranges != 0 ? -1 : minutes_elapsed - 1;
        //we do not consider the last minute because there is no rotting happening then, everything is already rotten
    }
};