class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string, vector<string>> mp;
        vector<vector<string>> anagrams;
        //pushing the strings into the hashmap with key as the sorted str
        for(string s : strs)
        {
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(s);
        }
        for(auto pair : mp)
        {
            anagrams.push_back(pair.second);
        }
        return anagrams;
    }
};