class Solution {
public:
    void generate(vector<int> &v, int sum, int idx, vector<int> &arr, vector<vector<int>> &answers, int target){
        if(sum == target && idx <= arr.size()){
            answers.push_back(v);
            return;
        }
        if(idx == arr.size() || sum > target)   return;
        //taking the current element
        v.push_back(arr[idx]);
        generate(v, sum + arr[idx], idx + 1, arr, answers, target);
        v.pop_back();
        //skipping the current element - we will never take this element again
        int curr = arr[idx];
        while(idx < arr.size() && arr[idx] == curr) idx++;
        generate(v, sum, idx, arr, answers, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answers;
        vector<int> v;
        generate(v, 0, 0, candidates, answers, target);
        return answers;
    }
};