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
    }
};