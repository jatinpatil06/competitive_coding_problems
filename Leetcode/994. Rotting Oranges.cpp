class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutesElapsed = 0, m = grid.size(), n = grid[0].size(), freshOranges = 0;
        queue<pair<int, int>> qu;
        //finding all the rotten oranges initially
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) qu.push({i, j});
                else if(grid[i][j] == 1)    freshOranges++;
            }
        if(qu.empty() && freshOranges == 0)  return 0;
        //now we will start rotting them each minute
        while(!qu.empty()){
            //we have to pop only those oranges that are scheduled to rot in this minute
            int num_of_oranges_this_min = qu.size();
            for(int i = 0; i < num_of_oranges_this_min; i++){
                pair<int, int> coords = qu.front();
                qu.pop();
                int x = coords.first;
                int y = coords.second;
                //now we will add the oranges that are to be rotten in the next minute to the queue
                int dx[4] = {-1, 0, 1, 0};
                int dy[4] = {0, 1, 0, -1};
                for(int z = 0; z < 4; z++){
                    int new_x = x + dx[z];
                    int new_y = y + dy[z];
                    if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || grid[new_x][new_y] != 1)   continue;
                    else{
                        grid[new_x][new_y] = 2;
                        qu.push({new_x, new_y});
                        freshOranges--;
                    }
                }
            }
            minutesElapsed++;
        }
        //if all oranges aren't rotten
        if(freshOranges != 0)   return -1;
        return minutesElapsed - 1;
    }
};