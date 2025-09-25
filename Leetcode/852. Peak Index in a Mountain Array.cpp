class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size() - 1;
        int low = 0, high = n - 1;
        int answer = -1;
        while(low <= high)
        {
            int mid = (high - low) / 2 + low;
            if(mid == n - 1 || arr[mid] > arr[mid + 1])
            {
                answer = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        return answer;
    }
};