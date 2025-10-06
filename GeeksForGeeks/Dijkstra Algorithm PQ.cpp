// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //we first need to construct the adjacency list
        vector<vector<pair<int, int>>> adj_list(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj_list[u].push_back({w, v});
            adj_list[v].push_back({w, u});
        }
        //storing the distances of each node from source
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({dist[src], src});
        while(!pq.empty()){
            //get the node with the least distance
            int nodeDist = pq.top().first;
            int Node = pq.top().second;
            pq.pop();
            //skipping stale entries
            if(nodeDist > dist[Node])   continue;
            //for all adjacent neighbours
            for(auto neighbour : adj_list[Node]){
                int adjNode = neighbour.second;
                int adjDist = neighbour.first;
                if(dist[Node] + adjDist < dist[adjNode]){
                    dist[adjNode] = dist[Node] + adjDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        
        }
        return dist;
    }
};