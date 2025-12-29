class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*  Brute Force Approach with TC = O(N ^ 2)
        int max_prod = nums[0], n = nums.size();
        for(int i = 0; i < n; i++){
            int cur_prod = 1;
            for(int j = i; j < n; j++){
                cur_prod *= nums[j];
                max_prod = max(cur_prod, max_prod);
            }
        }
        return max_prod;
        */
    }
};