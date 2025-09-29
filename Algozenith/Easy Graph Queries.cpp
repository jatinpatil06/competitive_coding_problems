#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> graph;
vector<int> visited;
void dfs(int vertex, int colour)
{
    //colouring the unvisited node
    if(visited[vertex] == 0)    visited[vertex] = colour;
    //now we will colour all the reachable nodes
    for(auto v : graph[vertex]) if(visited[v] == 0) dfs(v, colour);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    //defining the adjacency list
    graph.resize(n + 1);
    visited.resize(n + 1);
    while(m--)
    {
        //creating the adjacency list from the input edges
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //now we will run dfs and colour each component
    int num_components = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            num_components++;
            dfs(i, num_components);
        }
    }
    //now we will calculate the size of each connected component
    map<int, int> component_sizes;
    for(int i = 1; i <= n; i++) component_sizes[visited[i]]++;

    //now for the queries to be done on the graph
    while(q--)
    {
        int query;
        cin >> query;
        int x, y;
        if(query == 1)
        {
            cin >> x;
            cout << component_sizes[visited[x]] << "\n";
        }
        else if(query == 2)
        {
            cin >> x >> y;
            if(visited[x] == visited[y])    cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}