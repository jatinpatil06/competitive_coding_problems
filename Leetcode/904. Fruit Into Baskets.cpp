class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*
        Brute Force = O(n ^ 2)
        int max_len = 0, n = fruits.size();
        for(int i = 0; i < n; i++){
            unordered_map<int, int> mp;
            for(int j = i; j < n; j++){
                mp[fruits[j]]++;
                if(mp.size() == 2)  max_len = max(max_len, j - i + 1);
                else if(mp.size() > 2)  break;
            }
        }
        return max_len;

        An optimal apporach would be to use the two pointers approach
        */
        int max_len = 0, n = fruits.size();
        unordered_map<int, int> mp;
        int l = 0;
        for(int r = 0; r < n; r++){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0)  mp.erase(fruits[l]);
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};