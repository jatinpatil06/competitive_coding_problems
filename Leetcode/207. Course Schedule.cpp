class Solution {
public:
    bool dfsCycle(int node, vector<int> &visited, vector<int> &pathVisited, vector<vector<int>> &g){
        visited[node] = 1;
        pathVisited[node] = 1;
        //for all the adjacent neighbours
        for(auto adjNode : g[node]){
            if(!visited[adjNode] && dfsCycle(adjNode, visited, pathVisited, g))
                return true;
            else if(visited[adjNode] && pathVisited[adjNode])
                return true;
        }
        pathVisited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //creating the adjacency list first
        vector<vector<int>> g(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int prerequisite = prerequisites[i][1];
            int nextCourse = prerequisites[i][0];
            g[prerequisite].push_back(nextCourse);
        }
        //now we will detect cycles using DFS
        vector<int> visited(numCourses), pathVisited(numCourses);
        for(int i = 0; i < numCourses; i++)
            if(dfsCycle(i, visited, pathVisited, g) == true) return false;
        return true;
    }
};