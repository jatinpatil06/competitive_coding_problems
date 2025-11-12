class Solution {
  public:
    vector<int> dp;
    int train(int idx, int activity, vector<vector<int>>& arr, vector<vector<int>> &dp){
        int n = arr.size();
        int A[3] = {0};
        if(idx == n)    return 0;
        if(dp[idx][activity] != -1) return dp[idx][activity];
        for(int i = 0; i < 3; i++)
            if(activity != i)   A[i] = arr[idx][i] + train(idx + 1, i, arr, dp);
        int score = max(max(A[0], A[1]), A[2]);
        return dp[idx][activity] = score;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        //Without memoization, TC = O(3 ^ N)
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return train(0, 3, arr, dp);
        
    }
};