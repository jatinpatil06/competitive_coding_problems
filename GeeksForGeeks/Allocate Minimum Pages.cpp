class Solution {
  public:
    bool check(vector<int> &arr, int k, int max_pages){
        int cur_pages = arr[0];
        int no_of_students = 1;
        for(int i = 1; i < arr.size(); i++){
            cur_pages += arr[i];
            if(cur_pages > max_pages){
                cur_pages = arr[i];
                no_of_students++;
            }
        }
        return no_of_students <= k ? true : false;
    }
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size())  return -1;
        long long int sum = 0;
        int min_pages = INT_MIN;
        for(auto n : arr){
            sum += n;
            min_pages = max(min_pages, n);
        }
        long long int ans = -1, low = min_pages, high = sum;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(arr, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return ans;
    }
};