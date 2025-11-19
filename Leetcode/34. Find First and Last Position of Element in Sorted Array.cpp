class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), start = -1, end = -1;
        /*  Brute Force with TC = O(N)
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                start = min(start, i);
                end = max(end, i);
            }
        }
        if (start == n) return {-1, -1};
        else    return {start, end};
            An optimal approach would be to use binary search, since the array is sorted
        */
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(nums[mid] == target)  start = mid;
            if(nums[mid] >= target) high = mid - 1;
            else    low = mid + 1;
        }
        low = 0, high = n - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(nums[mid] == target)  end = mid;
            if(nums[mid] <= target) low = mid + 1;
            else    high = mid - 1;
        }
        if (start == -1) return {-1, -1};
        else    return {start, end};
    }
};