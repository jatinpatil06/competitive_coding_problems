#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
void dfs(int node, int component)
{
    visited[node] = component;
    //for all adjacent nodes, run dfs
    for(int i = 0; i < g[node].size(); i++)
    {
        if(visited[g[node][i]] == 0)
            dfs(g[node][i], component);
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    //creating the adjacency list for the graph
    visited.resize(n + 1);
    g.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //now we will perform dfs too find out the connected components and keep track of which node belongs to what connected component
    int component = 1;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i, component++);
        }
    }

    //size of each connected component
    map<int, int> sizes;
    for(int i = 1; i <= n; i++)
        sizes[visited[i]] += 1;
    
    while(q--)
    {
        int query;
        cin >> query;
        if(query == 1)
        {
            int x;
            cin >> x;
            cout << sizes[visited[x]] << "\n";
        }
        else if(query == 2)
        {
            int x, y;
            cin >> x >> y;
            if(visited[x] == visited[y])
                cout << "YES\n";
            else    
                cout << "NO\n";
        }
    }
    return 0;
}