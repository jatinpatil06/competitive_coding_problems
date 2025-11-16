class Solution {
  public:
    int nthRoot(int n, int m) {
        if(m == 0)  return 0;
        int low = 1, high = m;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            int x = 1;
            for(int i = 0; i < n; i++)  x *= mid;
            if(x == m)  return mid;
            else if(x > mid)    high = mid - 1;
            else    low = mid + 1;
        }
        return -1;
    }
};