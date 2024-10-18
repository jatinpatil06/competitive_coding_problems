class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = 0;
        int ub = nums.size() -1 ;
        vector <int> ans = {-1,-1};
        int i,j;
        
        while(lb <= ub)
        {
            int mid = (lb + ub) / 2;
            if(nums[mid] == target)
            {
                i = mid;
                j = mid;
                while(i > 0 && nums[i -1] == target)
                    i--;
                while(j < nums.size()-1 && nums[j + 1] == target)
                    j++;
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
            if(target > nums[mid])
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        return ans;
    }
};