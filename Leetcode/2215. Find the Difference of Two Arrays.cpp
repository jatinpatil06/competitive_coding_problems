class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer;
        vector<int> temp1;
        vector<int> temp2;
        map <int, int> mp1;
        map <int, int> mp2;
        for(auto it = nums1.begin(); it != nums1.end(); it++)
            mp1[*it] = 1;
        for(auto it = nums2.begin(); it != nums2.end(); it++)
            mp2[*it] = 1;
        for(int i = 0; i < nums1.size(); i++)
            if(mp1[nums1[i]] > 0 && mp2[nums1[i]] == 0)
            {
                temp1.push_back(nums1[i]);
                mp1[nums1[i]] = 0;
            }
        for(int i = 0; i < nums2.size(); i++)
            if(mp2[nums2[i]] > 0 && mp1[nums2[i]] == 0)
            {
                temp2.push_back(nums2[i]);
                mp2[nums2[i]] = 0;
            }
        answer.push_back(temp1);
        answer.push_back(temp2);
        return answer;
    }
};