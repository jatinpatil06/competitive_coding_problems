class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return mid;
            //checking which half is sorted
            if(nums[low] <= nums[mid]){
                //checking which half the element is present in
                //if present in left half we will search there
                if(nums[low] <= target && target < nums[mid])   high = mid - 1;
                //else we will chop off the left half and move to right half
                else    low = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[high])  low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};