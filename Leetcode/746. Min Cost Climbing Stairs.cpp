class Solution {
public:
    int coster(vector<int>& cost_uptill, vector<int> &cost, int n)
    {
        if(cost_uptill[n] != -1)    return cost_uptill[n];
        return cost_uptill[n] = min(cost[n - 1] + coster(cost_uptill, cost, n - 1), cost[n - 2] + coster(cost_uptill, cost, n - 2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cost_uptill(1001, -1);
        cost_uptill[0] = 0;
        cost_uptill[1] = 0;
        return coster(cost_uptill, cost, cost.size());
    }
};