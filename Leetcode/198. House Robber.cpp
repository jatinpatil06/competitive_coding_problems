class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], prev = nums[0], prev2 = 0;
        for(int i = 1; i < n; i++){
            int take = nums[i] + prev2;
            int not_take = prev;
            curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
class Solution {
public:
    int robbing(vector<int> &nums, vector<int> &max_profit, int n){
        if(n < 0)   return 0;
        if(n == 0)  return nums[0];
        if(max_profit[n] == -1){
            int pick = robbing(nums, max_profit, n - 2);
            int not_pick = robbing(nums, max_profit, n - 1);
            max_profit[n] = max(nums[n] + pick, not_pick);
        }
        return max_profit[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_profit(n, -1);
        return robbing(nums, max_profit, n - 1);
    }
};