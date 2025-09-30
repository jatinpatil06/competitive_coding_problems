#include<bits/stdc++.h>
#define int long long int
using namespace std;
vector<vector<char>> room_map;
void dfs(int i, int j, int n, int m)
{
    if(i < 0 || j < 0 || i >= n || j >= m || room_map[i][j] == '#') return;
    room_map[i][j] = '#';
    //now we will dfs for all 4 of the adjacent neighbours
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    for(int z = 0 ; z < 4; z++)
        dfs(i + dx[z], j + dy[z], n, m);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    room_map.resize(n, vector<char>(m));
    //creating the map
    for(int i = 0; i <n ; i++)
        for(int j = 0; j < m; j++)
            cin >> room_map[i][j];
    //now we will find the number of connected components aka the number of rooms
    int num_components = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(room_map[i][j] == '.')
            {
                num_components++;
                dfs(i, j, n, m);
            }
        }
    cout << num_components;
    return 0;
}