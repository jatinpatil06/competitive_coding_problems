class Solution {
public:
    vector<vector<int>> answers;
    void generate(int idx, vector<int> v, vector<int> &nums){
        int n = nums.size();
        if(idx == n)    answers.push_back(v);
        else{
            //include the element
            v.push_back(nums[idx]);
            generate(idx + 1, v, nums);
            //do not include the element
            v.pop_back();
            int curr = nums[idx];
            while(idx < n && nums[idx] == curr)    idx++;
            generate(idx, v, nums);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generate(0, {}, nums);
        return answers;
    }
};