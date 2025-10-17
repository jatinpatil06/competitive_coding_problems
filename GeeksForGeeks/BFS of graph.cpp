class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> traverse;
        vector<int> visited(adj.size(), 0);
        queue<int> qu;
        qu.push(0);
        visited[0] = 1;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            traverse.push_back(node);
            //for all adjacent neighbours
            for(auto neigh : adj[node]){
                if(!visited[neigh]){
                    visited[neigh] = 1;
                    qu.push(neigh);
                }
            }
        }
        return traverse;
    }
};