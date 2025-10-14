class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans1 = -1, ans2 = -1, low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) ans1 = mid;
            if(nums[mid] >= target) high = mid - 1;
            else    low = mid + 1;
        }
        low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) ans2 = mid;
            if(nums[mid] <= target) low = mid + 1;
            else    high = mid - 1;
        }
        return {ans1, ans2};
    }
};