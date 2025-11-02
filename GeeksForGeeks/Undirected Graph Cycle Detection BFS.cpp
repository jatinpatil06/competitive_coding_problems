class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(V);
        vector<int> visited(V, 0);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        //Applying BFS for cycle detection
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                queue<pair<int, int>> qu;
                qu.push({i, -1});
                visited[i] = 1;
                while(!qu.empty()){
                    int node = qu.front().first;
                    int parent = qu.front().second;
                    qu.pop();
                    for(auto neighbour : adj_list[node]){
                        if(!visited[neighbour]){
                            visited[neighbour] = 1;
                            qu.push({neighbour, node});
                        }
                        else if(parent != neighbour)    return true;
                    }
                }
            }
        }
        return false;
    }
};