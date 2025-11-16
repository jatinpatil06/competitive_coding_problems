class Solution {
public:
    bool check(int maxWeight, int days, vector<int> &weights){
        int weightLeft = 0, dayCount = 0;
        for(int i = 0; i < weights.size(); i++){
            if(weightLeft - weights[i] < 0){
                dayCount++;
                weightLeft = maxWeight;
            }
            weightLeft -= weights[i];
        }
        return dayCount <= days ? 1 : 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        for(int i = 0; i < weights.size(); i++){
            low = max(low, weights[i]);
            high += weights[i];
        }
        /*  Brute Force Approach, trying out all capacities possible
        for(; low <= high; low++){
            if(check(low, days, weights))   return low;
        }
        */
        int ans = -1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(check(mid, days, weights)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};