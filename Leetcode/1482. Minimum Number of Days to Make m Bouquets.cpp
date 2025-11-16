class Solution {
public:
    bool check(int day, int bouquetSize, int numBouquets, vector<int> &bloom){
        int n = bloom.size(), c = 0, bouquets = 0;
        for(int i = 0; i < n; i++){
            if(bloom[i] <= day){
                c++;
                if(c == bouquetSize){
                    bouquets++;
                    c = 0;
                }
            }
            else    c = 0;
        }
        return bouquets >= numBouquets ? 1 : 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = INT_MAX, high = INT_MIN, n = bloomDay.size();
        for(int i = 0; i < n; i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }
        /*  Brute Force Approach
        for(; low <= high; low++){
            if(check(low, k, m, bloomDay))  return low;
        }
            An optimal approach would be to use Binary Search on Answer
        */
        int ans = -1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(check(mid, k, m, bloomDay)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};