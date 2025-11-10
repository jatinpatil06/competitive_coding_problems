class Solution {
  public:
    int countSubstring(string s) {
        /*
        Brute Force Approach with TC = O(N ^ 2)
        int n = s.length(), count = 0;
        for(int i = 0; i < n; i++){
            int freq[3] = {0};
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                if(freq[0] > 0 && freq[1] > 0 && freq[2] > 0)   count++;
            }
        }
        return count;
        
        An Optimal Approach would be to use 2 pointers
        */
        int n = s.length(), count = 0;
        int l = 0, r = 0;
        unordered_map<char, int> freq;
        for(; r < n; r++){
            freq[s[r]]++;
            while(freq.size() >= 3){
                freq[s[l]]--;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            count += r - l + 1;
        }
        return (n * (n + 1)) / 2 - count;
    }
};