class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map <int, int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sum = 0, connected = 0, n = points.size();
        pq.push({0, 0});
        while(!pq.empty() && connected < n){
            int cur_dist = pq.top().first;
            int cur_idx = pq.top().second;
            pq.pop();
            if(visited[cur_idx])    continue;
            visited[cur_idx] = 1;
            sum += cur_dist;
            connected++;
            //for all other points
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    int adj_dist = abs(points[i][0] - points[cur_idx][0]) + abs(points[i][1] - points[cur_idx][1]);
                    pq.push({adj_dist, i});
                }
            }
        }
        return sum;
    }
};