class Solution {
  public:
    bool dfs(vector<vector<int>> &adj_list, vector<int> &visited, vector<int> &pathVisited, int node){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto neighbour : adj_list[node]){
            if(!visited[neighbour]){
                if(dfs(adj_list, visited, pathVisited, neighbour) == true)   return true;
            }
            else if(visited[neighbour]){
                if(pathVisited[neighbour])  return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj_list(V);
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj_list[u].push_back(v);
        }
        //checking for all components
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(adj_list, visited, pathVisited, i) == true)  return true;
            }
        }
        return false;
    }
};