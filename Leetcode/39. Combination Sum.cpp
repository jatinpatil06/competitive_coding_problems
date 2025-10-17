class Solution {
public:
    void generate(vector<int> &v, int sum, int idx, int target, vector<int> &candidates, vector<vector<int>> &answers){
        if(idx == candidates.size() || sum > target)    return;
        if(sum == target){
            answers.push_back(v);
            return;
        }
        else{
            //not taking the current element
            generate(v, sum, idx + 1, target, candidates, answers);
            v.push_back(candidates[idx]);
            sum += candidates[idx];
            //taking the current element once more
            generate(v, sum, idx, target, candidates, answers);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answers;
        vector<int> v;
        generate(v, 0, 0, target, candidates, answers);
        return answers;
    }
};