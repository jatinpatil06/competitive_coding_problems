class Solution {
public:
    int jump(vector<int> &dp, vector<int> &heights, int n, int k){
        if(n == 0)  return 0;
        if(dp[n] != -1) return dp[n];
        int cur_min = INT_MAX;
        for(int i = 1; i <= k; i++){
            int kth_jump = INT_MAX;
            if(n - i >= 0)  kth_jump = jump(dp, heights, n - i, k) + abs(heights[n] - heights[n - i]);
            cur_min = min(cur_min, kth_jump);
        }
        return dp[n] = cur_min;
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, - 1);
        jump(dp, heights, n - 1, k);
        return dp[n - 1];
    }
};
