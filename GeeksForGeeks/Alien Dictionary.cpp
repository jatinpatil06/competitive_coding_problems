class Solution {
  public:
    string findOrder(vector<string> &words) {
        string answer = "";
        int n = words.size();
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inDegree;
        //initializing inDegree
        //Only adjacent words provide direct ordering constraints
        for(int i = 0; i < n; i++){
            string word = words[i];
            for(char ch : word) inDegree[ch] = 0;
        }
        //creating the graph
        for(int i = 0; i < n - 1; i++){
                int p = 0, len1 = words[i].length(), len2 = words[i + 1].length();
                while(p < len1 && p < len2 && words[i][p] == words[i + 1][p])   p++;
                if(p == len2 && len1 > len2)    return "";
                if(p < len1 && p < len2){
                    int u = words[i][p], v = words[i + 1][p];
                    graph[u].push_back(v);
                    inDegree[v]++;
                }    
                
        }
        //Applying Kahn's algorithm to find a suitable ordering
        queue<char> qu;
        for(auto p : inDegree){
            if(p.second == 0)   qu.push(p.first);
        }
        while(!qu.empty()){
            char node = qu.front();
            qu.pop();
            answer += node;
            for(auto neighbour : graph[node]){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0)    qu.push(neighbour);
            }
        }
        
        return answer.length() == inDegree.size() ? answer : "";
    }
};