class Solution {
  public:
    bool check(vector<int> &stalls, int k, int min_dist){
        int cows_placed = 1, last_idx = 0;
        for(int i = 1; i < stalls.size(); i++){
            if(abs(stalls[i] - stalls[last_idx]) >= min_dist){
                cows_placed++;
                last_idx = i;
            }
        }
        return cows_placed >= k ? true : false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls.back() - stalls.front(), ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(stalls, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else    high = mid - 1;
        }
        return ans;
    }
};