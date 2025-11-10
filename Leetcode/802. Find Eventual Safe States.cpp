class Solution {
public:
    vector<int> pathVisited, visited, safeNodes;
    bool isCycle(vector<vector<int>>& graph, int node){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto neighbour : graph[node]){
            if(!visited[neighbour]){
                if(isCycle(graph, neighbour))    return true;
            }
            else if(pathVisited[neighbour]) return true;
        }
        pathVisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        for(int node = 0; node < V; node++){
            pathVisited.resize(V, 0);
            visited.resize(V, 0);
            if(!isCycle(graph, node))   safeNodes.push_back(node);
        }
        return safeNodes;
    }
};