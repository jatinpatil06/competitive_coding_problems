#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    int num_comp = 0;
    map<int, int> perimeter;
    map<int, int> area;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //now we will perform dfs if its an island each time
            if(grid[i][j] == '#' && !visited[i][j])
            {
                num_comp += 1;
                queue<pair<int, int>> qu;
                qu.push({i, j});
                visited[i][j] = true;
                area[num_comp] = 1;
                while(!qu.empty())
                {
                    pair<int, int> coord = qu.front();
                    qu.pop();
                    for(int z = 0; z < 4; z++)
                    {
                        int x = coord.first + dx[z];
                        int y = coord.second + dy[z];
                        if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == '.')
                            perimeter[num_comp] += 1;
                        else if(grid[x][y] == '#' && !visited[x][y])
                        {
                            qu.push({x, y});
                            visited[x][y] = true;
                            area[num_comp] += 1;
                        }
                    }
                }
            }
        }
    }
    //now we sort the map and show the one with the largest area, and smaller perimeter
    int best_area = 0, best_perimeter = 0;
    for(auto& [comp, ar] : area)
    {
        int p = perimeter[comp];
        if(ar > best_area || (ar == best_area && p < best_perimeter))
        {
            best_perimeter = p;
            best_area = ar;
        }
    }
    cout << best_area << " " << best_perimeter;
    return 0;
}