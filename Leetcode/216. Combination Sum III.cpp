class Solution {
public:
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    void generate(vector<int> &v, int sum, int idx, vector<vector<int>> &answers, int &target, int k){
        if(sum > target || v.size() > k)    return;
        if(sum == target && v.size() == k){
            answers.push_back(v);
            return;
        }
        if(idx == nums.size())  return;
        //take a number
        v.push_back(nums[idx]);
        generate(v, sum + nums[idx], idx + 1, answers, target, k);
        v.pop_back();
        //do not take current number
        generate(v, sum, idx + 1, answers, target, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answers;
        vector<int> v;
        generate(v, 0, 0, answers, n, k);
        return answers;
    }
};