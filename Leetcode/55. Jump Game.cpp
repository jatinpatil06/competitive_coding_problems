class Solution {
public:
    /*
        Dynampic Programming with Memoization
    vector <int> dp;
    bool jumper(vector<int> &nums, int idx){
        int n = nums.size();
        if(idx == n - 1)    return dp[idx] = 1;
        else if(idx < n){
            if(dp[idx] != -1)   return dp[idx];
            for(int i = 1; i <= nums[idx]; i++){
                if(jumper(nums, idx + i) == true) return true;
            }
        }
        return dp[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), - 1);
        return jumper(nums, 0);
    }

        We can also try a greedy approach
    */
    bool canJump(vector<int>& nums){
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxReach)   return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};