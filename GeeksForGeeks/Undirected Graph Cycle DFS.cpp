class Solution {
  public:
    vector<int> visited;
    vector<vector<int>> graph;
    bool dfs(int node, int parent){
        visited[node] = 1;
        for(auto neighbour : graph[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour, node) == true)    return true;
            }
            else if(parent != neighbour)  return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        visited.resize(V, 0);
        graph.resize(V);
        for(int i = 0; i < n; i++){
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(i, -1) == true)  return true;
            }
        }
        return false;
    }
};