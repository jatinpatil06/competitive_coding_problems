class Solution {
  public:
    /*
    // Memoization approach with TC = O(n) & SC = O(n) + O(n)
    vector<int> min_cost;
    int climbing(vector<int> &height, int n){
        if(n <= 0)  return 0;
        if(n == 1)  return abs(height[1] - height[0]);
        if(min_cost[n] != -1)   return min_cost[n];
        int one_step = abs(height[n] - height[n - 1]) + climbing(height, n - 1);
        int two_step = abs(height[n] - height[n - 2]) + climbing(height, n - 2);
        return min_cost[n] = min(one_step, two_step);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        min_cost.resize(n, -1);
        return climbing(height, n - 1);
    }
    
    // Tabulation approach with TC = O(n) & SC = O(n)
    int minCost(vector<int>& height) {
        int n = height.size();
        if(n == 1)  return 0;
        vector<int> min_cost(n, -1);
        min_cost[0] = 0;
        min_cost[1] =  abs(height[1] - height[0]);
        for(int i = 2; i < n; i++){
            int one_step = abs(height[i] - height[i - 1]) + min_cost[i - 1];
            int two_step = abs(height[i] - height[i - 2]) + min_cost[i - 2];
            min_cost[i] = min(one_step, two_step);
        }
        return min_cost[n - 1];
    }
    
    Optimized Approach with TC = O(n) & SC = O(1)
    */
    int minCost(vector<int>& height){
        int n = height.size();
        if(n <= 1)  return 0;
        int prev2 = 0, prev = abs(height[1] - height[0]), curr;
        for(int i = 2; i < n; i++){
            int one_step = abs(height[i] - height[i - 1]) + prev;
            int two_step = abs(height[i] - height[i - 2]) + prev2;
            curr = min(one_step, two_step);
            prev2 = prev;
            prev = curr;
        }
        return prev;    //we return prev instead of curr, because curr will be uninitialized when n = 2, giving a wrong answer.
    }
};