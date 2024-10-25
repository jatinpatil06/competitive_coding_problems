class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map <int, int> mp1;
        for(auto val : arr)
            mp1[val] += 1;
        map <int,int> mp2;
        for(auto pair : mp1)
        {
            if(mp2[pair.second] != 0)
                return false;
            mp2[pair.second] = 1;
        }
        return true;
    }
};