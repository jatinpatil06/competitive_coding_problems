class Solution {
public:
    /*  Recursive approach with TC = O(N ^ 2)

    void generate(vector<int> &arr, vector<int> &v, int idx, vector<vector<int>> &answers){
        if(idx == arr.size()){
            answers.push_back(v);
            return;
        }
        //not taking this element
        generate(arr, v, idx + 1, answers);
        //taking this element
        v.push_back(arr[idx]);
        generate(arr, v, idx + 1, answers);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answers;
        vector<int> v;
        generate(nums, v, 0, answers);
        return answers;
    }
        Applying a bitmasking approach to generate all subsets
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answers;
        int n = nums.size();
        vector<int> v;
        for(int mask = 0; mask < pow(2, n); mask++){
            v.clear();
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)) v.push_back(nums[i]);
            }
            answers.push_back(v);
        }
        return answers;
    }
};