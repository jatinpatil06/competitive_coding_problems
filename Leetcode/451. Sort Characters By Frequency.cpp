class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char ch : s)    freq[ch]++;
        vector<pair<char, int>> sorted_freq(freq.begin(), freq.end());
        sort(sorted_freq.begin(), sorted_freq.end(), [] (auto &a, auto &b){
            return a.second > b.second;
        });
        string s_desc = "";
        for(auto p : sorted_freq){
            char ch = p.first;
            int freq = p.second;
            for(int i = 0; i < freq; i++)   s_desc += ch;
        }
        return s_desc;
    }
};