class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lb = 0;
        int ub = nums.size() - 1;
        while(lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if(nums[mid] == target)
                return mid;
            if(target > nums[mid])
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        return lb;
    }
};