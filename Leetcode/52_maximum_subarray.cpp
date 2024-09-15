class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum  = INT_MIN;
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            currSum += *it;
            maxSum = max(currSum, maxSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};