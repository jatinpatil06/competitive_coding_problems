class Solution {
public:
    int difference(string s1, string s2){
        int diff_count = 0;
        for(int i = 0; i < s1.size(); i++)  if(s1[i] != s2[i])  diff_count++;
        return diff_count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj_list;
        unordered_map<string, int> visited;
        wordList.push_back(beginWord);
        int n = wordList.size();

        //creating the adjacency list
        // for(int i = 0; i < n; i++){
        //     string cur_word = wordList[i];
        //     for(int j = 0; j < n; j++){
        //         if(difference(cur_word, wordList[j]) == 1){  
        //             adj_list[cur_word].push_back(wordList[j]);
        //             visited[cur_word] = 0;
        //         }
        //     }
        // }
        
        //now, we will find the shortest distance
        queue<string> qu;
        int dist = 1;
        qu.push(beginWord);
        visited[beginWord] = 1;
        while(!qu.empty()){
            int qu_size = qu.size();
            for(int i = 0; i < qu_size; i++){
                string cur_word = qu.front();
                qu.pop();
                if(cur_word == endWord) return dist;
                //the optimal approach is to generate neighbours on the fly
                vector<string> neighbours;
                for(int i = 0; i < n; i++){
                    if(difference(cur_word, wordList[i]) == 1)  neighbours.push_back(wordList[i]);
                }
                for(auto neighbour : neighbours){
                    if(!visited[neighbour]){
                        visited[neighbour] = 1; 
                        qu.push(neighbour);
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};