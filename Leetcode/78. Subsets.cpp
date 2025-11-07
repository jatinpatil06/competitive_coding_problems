class Solution {
public:
    void generate(vector<int> subset, int level, int n, vector<int> &nums, vector<vector<int>> &answers){
        if(level == n)  answers.push_back(subset);
        else{
            generate(subset, level + 1, n, nums, answers);
            subset.push_back(nums[level]);
            generate(subset, level + 1, n, nums, answers);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answers;
        generate({}, 0, nums.size(), nums, answers);
        return answers;

        /*Optimized Approach using Bit Masking
        vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); mask++){
            vector<int> subset;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i))    subset.push_back(nums[i]);
            }
            subsets.push_back(subset);
        }
        return subsets;
    }
        */
    }
};