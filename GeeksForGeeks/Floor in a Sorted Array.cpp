class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int floor_num = -1;
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] <= x){
                floor_num = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return floor_num;
    }
};
