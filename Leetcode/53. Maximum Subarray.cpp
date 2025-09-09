class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = nums[0], max_sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(cur_sum + nums[i] <= nums[i])    cur_sum = nums[i];
            else    cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};