class Solution {
public:
    vector<int> visited, pathVisited;
    stack<int> st;
    bool dfs(vector<vector<int>> &adj_list, int node){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto neighbour : adj_list[node]){
            if(!visited[neighbour]){
                if(dfs(adj_list, neighbour) == true)    return true;
            }
            else if(pathVisited[neighbour])    return true;
        }
        pathVisited[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 0);
        pathVisited.resize(numCourses, 0);
        vector<vector<int>> adj_list(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][1], v = prerequisites[i][0];
            adj_list[u].push_back(v);
        }
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfs(adj_list, i) == true)    return{};
            }
        }
        vector<int> ordering;
        while(!st.empty()){
            ordering.push_back(st.top());
            st.pop();
        }
        return ordering;
    }
};