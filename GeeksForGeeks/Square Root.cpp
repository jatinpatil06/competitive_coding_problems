class Solution {
  public:
    int floorSqrt(int n) {
        int ans = 1;
        /*  Brute Force TC = O(N)
        for(int i = 1; i < n; i++){
            if(i * i > n)   break;
            ans = i;
        }
        */
        int low = 1, high = n;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(mid * mid <= n){
                ans = mid;
                low = mid + 1;
            }
            else    high = mid - 1;
        }
        return ans;
    }
};