class DisjointSet{
    vector<int> size, parent;
    public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++)  parent[i] = i;
    }

    int findUltimateParent(int u){
        if(u == parent[u])  return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v)  return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    /*
    BRUTE FORCE APPROACH TO FIND NUMBER OF CONNECTED COMPONENTS
    void dfs(vector<vector<int>> &graph, int node, vector<int> &visited){
        visited[node] = 1;
        //for all its neighbours
        for(auto neighbour : graph[node]){
            if(!visited[neighbour]) dfs(graph, neighbour, visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)  return -1;
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);
        //building the graph
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0], v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //number of cables req = no of connected components - 1
        int num_components = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                num_components++;
                dfs(graph, i, visited);
            }
        }
        return num_components - 1;
    }
    */
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)  return -1;
        int num_components = 0;
        DisjointSet ds(n);
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0], v = connections[i][1];
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v))    ds.unionBySize(u, v);
        }
        for(int i = 0; i < n; i++)
            if(ds.findUltimateParent(i) == i)   num_components++;
        return num_components - 1;
    }
};