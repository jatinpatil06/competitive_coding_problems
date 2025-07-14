
#include <bits/stdc++.h>
using namespace std;


int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    Sx--; Sy--;
    Fx--; Fy--;
	queue<pair<int, int>> qu;
    vector<vector<int>> distance(N, vector<int>(N, -1));
    qu.push({Sx, Sy});
    distance[Sx][Sy] = 0;
    while(!qu.empty())
    {
        pair<int, int> coords = qu.front();
        qu.pop();
        for(int z = 0; z < 8; z++)
        {
            int x = coords.first + dx[z];
            int y = coords.second + dy[z];
            if(x >= 0 && x < N && y >= 0 && y < N && distance[x][y] == -1)
            {
                distance[x][y] = distance[coords.first][coords.second] + 1;
                qu.push({x, y});
            }
        }
    }
    if(distance[Fx][Fy] == -1)
        return -1;
    return distance[Fx][Fy];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
