#include<bits/stdc++.h>
#define int long long int
using namespace std;
class prioritize
{
    public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        return p1.second > p2.second;
    }
};

int n, m;
vector<int> dist;
vector<int> visited;
vector<vector<pair<int, int>>> g;
void dijkstra(int source)
{
    for(int i = 1; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
        visited[i] = 0;
    }
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, prioritize> pq;
    pq.push({source, dist[source]});

    while(!pq.empty())
    {
        pair<int, int> fs = pq.top();
        pq.pop();
        if(visited[fs.first] == 1)  continue;
        visited[fs.first] = 1;
        //now we will relax all its neighbours
        for(auto v : g[fs.first])
        {
            int neigh = v.first;
            int wt = v.second;
            if(dist[neigh] > dist[fs.first] + wt)
            {
                dist[neigh] = dist[fs.first] + wt;
                pq.push({neigh, dist[neigh]});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1);
    dist.resize(n + 1);
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}