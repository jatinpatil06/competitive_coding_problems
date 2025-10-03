class Solution {
public:
    int numberOfSubstrings(string s) {
        long long int n = s.size(), l = 0, r = 0, substrings = 0;
        unordered_map<int, int> mp;
        while(r < n){
            mp[s[r]]++;
            while(mp.size() == 3){
                mp[s[l]]--;
                if(mp[s[l]] == 0)   mp.erase(s[l]);
                l++;
            }
            substrings += r - l + 1;
            r++;
        }
        return (n * (n + 1)) / 2 - substrings;
    }
};