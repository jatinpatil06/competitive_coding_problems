class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), beauty = 0;
        for(int i = 0; i < n; i++){
            unordered_map<char, int> freq_mp;
            for(int j = i; j < n; j++){
                int max_freq = 0, min_freq = INT_MAX;
                freq_mp[s[j]]++;
                for(auto p : freq_mp){
                    int ch_freq = p.second;
                    max_freq = max(max_freq, ch_freq);
                    min_freq = min(min_freq, ch_freq);
                }
                beauty += max_freq - min_freq;
            }
        }
        return beauty;
    }
};