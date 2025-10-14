class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int ans1 = -1, ans2 = -1, low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == target)  ans1 = mid;
            if(arr[mid] >= target)  high = mid - 1;
            else    low = mid + 1;
        }
        low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == target)  ans2 = mid;
            if(arr[mid] <= target) low = mid + 1;
            else    high = mid - 1;
        }
        if(ans1 == -1)  return 0;
        return ans2 - ans1 + 1;
    }
};
