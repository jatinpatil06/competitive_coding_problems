class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //lets try applying dijkstra's algorithm to find the maximum shortest path length
        //building the adjacency list
        vector<vector<pair<int, int>>> adj_list(n + 1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj_list[u].push_back({w, v});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            //int nodeDist = pq.front().first;
            pq.pop();
            //for all adjacent nodes
            for(auto it : adj_list[node]){
                int edgeWeight = it.first;
                int adjNode = it.second;
                if(dist[node] + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dist[node] + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int max_time = 0;
        for(int i = 1; i <= n ; i++){
            if(dist[i] == INT_MAX)  return -1;
            max_time = max(max_time, dist[i]);
        }
        return max_time;
    }
};