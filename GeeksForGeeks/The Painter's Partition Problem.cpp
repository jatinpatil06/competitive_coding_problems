class Solution {
  public:
    bool check(int time, int k, vector<int> &arr){
        int painters = 0, timeLeft = 0;
        for(int i = 0; i < arr.size(); i++){
            if(timeLeft - arr[i] < 0){
                painters++;
                timeLeft = time;
            }
            timeLeft -= arr[i];
        }
        return painters <= k ? true : false;
    }
    int minTime(vector<int>& arr, int k) {
        int low = INT_MIN, high = 0;
        for(int i = 0; i < arr.size(); i++){
            low = max(low, arr[i]);
            high += arr[i];
        }
        /*  Brute Force solution with TC = )(N ^ 2)
        for(; low <= high; low++){
            if(check(low, k, arr))  return low;
        }
            An optimal approach would be to use Binary Search on Answer
        */
        int ans = -1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(check(mid, k, arr)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};