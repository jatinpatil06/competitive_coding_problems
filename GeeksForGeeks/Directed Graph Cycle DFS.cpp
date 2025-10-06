class Solution {
  public:
    bool dfsCycle(int node, vector<int> &visited, vector<int> &pathVisited, vector<vector<int>> &graph){
        visited[node] = 1;
        pathVisited[node] = 1;
        //for all the adjacent nodes
        for(auto adjNode : graph[node]){
            if(!visited[adjNode]){
                if(dfsCycle(adjNode, visited, pathVisited, graph) == true)
                    return true;
            }
            else if(visited[adjNode] && pathVisited[adjNode])
                return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        //creating the adjacency list
        vector<vector<int>> graph(V);
        for(int i = 0; i < edges.size(); i++)
            graph[edges[i][0]].push_back(edges[i][1]);
        vector<int> visited(V, 0), pathVisited(V, 0);
        for(int i = 0; i < V; i++)
            if(!visited[i] && dfsCycle(i, visited, pathVisited, graph))    return true;
        return false;
    }
};