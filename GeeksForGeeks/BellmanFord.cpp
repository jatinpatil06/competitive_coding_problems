// User function Template for C++
#define large_val 100000000
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, large_val);
        dist[src] = 0;
        for(int i = 1; i < V; i++){
            for(int j = 0; j < edges.size(); j++){
                int u = edges[j][0], v = edges[j][1], wt = edges[j][2];
                //we check that it is != large_val to avoid overflow, which might result in false true condition
                if(dist[u] != large_val && dist[u] + wt < dist[v])  dist[v] = dist[u] + wt;
            }
        }
        for(int j = 0; j < edges.size(); j++){
            int u = edges[j][0], v = edges[j][1], wt = edges[j][2];
            if(dist[u] != large_val && dist[u] + wt < dist[v])  return {-1};
        }
        return dist;
    }
};
