class Solution {
public:
    int max_adj_sum(vector<int> &arr){
        int prev = arr[0], prev2 = 0, curr;
        int n = arr.size();
        for(int i = 1; i < n; i++){
            int take = arr[i] + prev2;
            int not_take = prev;
            curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        int temp = nums.back();
        nums.pop_back();
        int max1 = max_adj_sum(nums);
        nums.erase(nums.begin());
        nums.push_back(temp);
        int max2 = max_adj_sum(nums);
        return max(max1, max2);
    }
};