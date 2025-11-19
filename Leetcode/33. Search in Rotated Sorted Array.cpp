class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        /*  Brute Force with TC = O(N)
        for(int i = 0; i < n; i++)  if(nums[i] == target)   return i;
            An optimal approach would be to use binary search
        */
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(nums[mid] == target) return mid;
            //is the left half sorted?
            if(nums[low] <= nums[mid]){
                //is the target present?
                if(nums[low] <= target && target <= nums[mid])  high = mid - 1;
                else    low = mid + 1;
            }
            //if the right half is sorted
            else{
                //is the target present?
                if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
                else    high = mid - 1;
            }
        }
        //** doesnt matter if we do mid +- 1 since we have already checked for mid
        return -1;
    }
};