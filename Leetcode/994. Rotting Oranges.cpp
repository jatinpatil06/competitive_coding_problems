class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> qu;
        //first we will all the rotten oranges to the queue and count all the fresh ones to keep track whether all have rotten or not
        int fresh = 0;  //as a stopping condition
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                    fresh += 1;
                else if(grid[i][j] == 2)
                    qu.push({i, j});
            }
        }
        int time = 0;
        //for each minute, we will find what oranges will rot in the next minute
        //since they rot simultaneously, we will keep track of how many rot per minute
        while(!qu.empty() && fresh > 0)
        {
            //we are finding whose all neighbours will rot next minute and adding them to the queue for subsequent processing
            int size = qu.size();   //this is to know how many oranges will rot this minute
            for(int i = 0; i < size; i++)
            {
                pair<int, int> coord = qu.front();
                qu.pop();
                for(int j = 0; j < 4; j++)
                {
                    int x = coord.first + dx[j];
                    int y = coord.second + dy[j];
                    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        fresh--;
                        qu.push({x, y});
                    }
                }
            }
            time += 1;
        }
        if(fresh != 0)
            return -1;
        return time;
    }
};