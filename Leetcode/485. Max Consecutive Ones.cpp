class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = -1, r = 0, max_len = 0;
        for(; r < nums.size(); r++){
            if(nums[r] == 0)    l = r;
            max_len = max(max_len, r - l);
        }
        return max_len;
    }
};