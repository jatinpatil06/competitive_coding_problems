class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1;
        if(n == 0)  return {-1, -1};
        vector<int> answers(2, -1);
        //finding lower bound
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target)
            {
                answers[0] = mid;
                high = mid - 1;
            }
            else    low = mid + 1;
        }
        if(answers[0] == -1 || nums[answers[0]] != target)    answers[0] = -1;
        //finding upper bound
        low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target)
            {
                answers[1] = mid;
                low = mid + 1;
            }
            else    high = mid - 1;
        }
        if(answers[0] == -1 || nums[answers[1]] != target)    answers[1] = -1;
        return answers;
    }
};