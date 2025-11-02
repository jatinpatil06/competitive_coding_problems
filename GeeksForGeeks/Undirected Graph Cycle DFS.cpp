class Solution {
  public:
    bool dfs(vector<vector<int>> &adj_list, vector<int> &visited, int node, int parent){
        visited[node] = 1;
        for(auto neighbour : adj_list[node]){
            if(!visited[neighbour]){
                if(dfs(adj_list, visited, neighbour, node) == true) return true;
            }
            else if(parent != neighbour)    return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(V);
        vector<int> visited(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(adj_list, visited, i, -1))   return true;
            }
        }
        return false;
    }
};