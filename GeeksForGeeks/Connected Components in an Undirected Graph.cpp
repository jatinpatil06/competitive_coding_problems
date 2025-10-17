
class Solution {
  public:
    void dfs(vector<vector<int>> &adj_list, int node, vector<vector<int>> &components, int component_num, vector<int> &visited){
        visited[node] = 1;
        components[component_num].push_back(node);
        for(auto neigh : adj_list[node]){
            if(!visited[neigh]) dfs(adj_list, neigh, components, component_num, visited);
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(V);
        vector<int> visited(V, 0);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<vector<int>> components;
        int component_num = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){ 
                components.push_back({});
                dfs(adj_list, i, components, component_num, visited);
                component_num++;
            }
        }
        return components;
    }
};
