class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> colour_freq;
        for(int i = 0; i < nums.size(); i++)    colour_freq[nums[i]]++;
        int i = 0;
        for(i = 0; i < colour_freq[0]; i++) nums[i] = 0;
        for(; i < colour_freq[0] + colour_freq[1]; i++) nums[i] = 1;
        for(; i < colour_freq[0] + colour_freq[1] + colour_freq[2]; i++) nums[i] = 2;
    }
};