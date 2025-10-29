class Solution {
public:
    vector<int> dp;
    int calculate(vector<int> &coins, int value){
        if(value == 0)  return 0;
        if(value < 0)   return 1e9;
        if(dp[value] != -1) return dp[value];
        int min_coins = 1e9;
        for(int i = 0; i < coins.size(); i++){
            min_coins = min(min_coins, calculate(coins, value - coins[i]) + 1);
        }
        return dp[value] = min_coins;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);
        int ans = calculate(coins, amount);
        return ans == 1e9 ? -1 : ans;
    }
};