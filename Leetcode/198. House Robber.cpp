class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr = nums[0], prev = nums[0], prev2 = 0;
        for(int i = 1; i < n; i++){
            int take = nums[i] + prev2;
            int not_take = prev;
            curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};