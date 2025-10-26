class Solution {
public:
    vector<int> dp;
    int expense(vector<int>&days, vector<int>&costs, int idx){
        int n = days.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1)   return dp[idx];
        int min_expense = INT_MAX;
        //if we take a one day ticket
        int next_day = idx + 1;
        int one_day = costs[0] + expense(days, costs, next_day);
        //if we take a seven day ticket
        while(next_day < n && days[next_day] <= days[idx] + 6)  next_day++;
        int seven_day = costs[1] + expense(days, costs, next_day);
        //if we take a thirty day ticket
        while(next_day < n && days[next_day] <= days[idx] + 29)  next_day++;
        int thirty_day = costs[2] + expense(days, costs, next_day);
        min_expense = min(one_day, seven_day);
        min_expense = min(min_expense, thirty_day);
        return dp[idx] = min_expense;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1);
        return expense(days, costs, 0);
    }
};