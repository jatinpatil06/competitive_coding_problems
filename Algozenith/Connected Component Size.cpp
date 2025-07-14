#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];
        //now we will perform bfs on each component
        int num_comp = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                {
                    num_comp += 1;
                    queue<pair<int, int>> qu;
                    qu.push({i, j});
                    grid[i][j] = 1;
                    vector<pair<int, int>> current_comp_coords;
                    current_comp_coords.push_back({i, j});
                    while(!qu.empty())
                    {
                        pair<int, int> coords = qu.front();
                        qu.pop();
                        for(int z = 0; z < 4; z++)
                        {
                            int x = coords.first + dx[z];
                            int y = coords.second + dy[z];
                            if(!(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 0))
                            {
                                qu.push({x, y});
                                grid[x][y] = 1;
                                current_comp_coords.push_back({x, y});
                            }
                        }
                    }
                    for(int z = 0; z < current_comp_coords.size(); z++)
                {
                    if(current_comp_coords.size() == 1)
                        grid[current_comp_coords[z].first][current_comp_coords[z].second] = 0;
                    else
                        grid[current_comp_coords[z].first][current_comp_coords[z].second] = current_comp_coords.size();
                }
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout << grid[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}