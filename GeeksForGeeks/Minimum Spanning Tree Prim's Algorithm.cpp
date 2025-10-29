class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        //creating the adjacency list
        vector<vector<pair<int, int>>> adj_list(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj_list[u].push_back({v, w});
            adj_list[v].push_back({u, w});
        }
        // format of priority queue is (weight, node), you can also use (weight, node, parent), in case we need edges of the MST
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, 0);
        int sum = 0;
        //starting from the first node
        pq.push({0, 0});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int wt = temp.first, node = temp.second;
            if(!visited[node]){
                visited[node] = 1;
                sum += wt;
                //for all adjacent neighbours
                for(auto temp2 : adj_list[node]){
                    int adj_node = temp2.first, adj_wt = temp2.second;
                    if(!visited[adj_node])  pq.push({adj_wt, adj_node});
                }
            }
        }
        return sum;
    }
};