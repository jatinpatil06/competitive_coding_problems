class Solution {
public:
    void dfs(vector<vector<int>> & isConnected, int vertex, vector<int> &visited){
        visited[vertex] = 1;
        int n = isConnected.size();
        for(int i = 0; i < n; i++)
            if(isConnected[vertex][i] && !visited[i]) dfs(isConnected, i, visited);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int no_of_cities = 0, n = isConnected.size();
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++)
            if(!visited[i]){
                no_of_cities++;
                dfs(isConnected, i, visited);
            }
        return no_of_cities;
    }
};