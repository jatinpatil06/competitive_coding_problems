class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int, int> mp;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            if(mp.find(*it) == mp.end())
                mp[*it] = *it;
            else return true;
        }
        return false;
    }
};