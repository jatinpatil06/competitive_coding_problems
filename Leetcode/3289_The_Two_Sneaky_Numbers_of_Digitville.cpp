class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int, int> mp;
        vector<int> sneakers;
        for(auto num = nums.begin(); num != nums.end(); num++)
        {
            if(mp[*num] == 0 || mp[*num] > 1)
                mp[*num] += 1;
            else
                sneakers.push_back(*num);
        }
        return sneakers;
    }
};