class Solution {
  public:
    void topoSortDFS(int node, vector<int> &visited, vector<int> &ordering, vector<vector<int>> &g){
        visited[node] = 1;
        //for all the adjacent neighbours
        for(auto adjNode : g[node]){
            if(!visited[adjNode])
                topoSortDFS(adjNode, visited, ordering, g);
        }
        ordering.push_back(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //creating the adjacency list
        vector<vector<int>> g(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            g[u].push_back(v);
        }
        vector<int> ordering, visited(V, 0);
        for(int i = 0; i < V; i++)
            if(!visited[i]) topoSortDFS(0, visited, ordering, g);
        reverse(ordering.begin(), ordering.end());
        return ordering;
    }
};