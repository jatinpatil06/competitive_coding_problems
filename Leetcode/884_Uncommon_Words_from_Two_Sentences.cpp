class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        //defining the hashmap to keep track of the frequencies
        map<string, int> mp;
        string word;
        stringstream ss1(s1);
        stringstream ss2(s2);
        vector <string> line1;
        vector <string> line2;
        vector <string> unique_words;
        while(ss1 >> word)
        {
            mp[word] += 1;
            line1.push_back(word);
        }
        while(ss2 >> word)
        {
            mp[word] += 1;
            line2.push_back(word);
        }
        for(auto &word : mp)
        {
            if(word.second == 1)
                unique_words.push_back(word.first);
        }
        
        return unique_words;
    }
};