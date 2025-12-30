class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            We fix one element and use a two pointers approach to find unique pairs that sum up to the target
            TC = O(nlogn + n^2) SC + O(n)
        */
        sort(nums.begin(), nums.end());
        vector<vector<int>> answers;
        int i = 0, n = nums.size();
        while(i < n){
            int curr = nums[i];
            int target = -curr;
            int j = i + 1, k = n - 1;
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum == target){
                    answers.push_back({curr, nums[j], nums[k]});
                    j++;
                    k--;
                    //we will not include i and j anymore
                    //we are moving both i and j because there is only one unique combination of i and j that can sum up to the desired target
                    while(j < k && nums[j] == nums[j - 1])  j++;
                    while(k > j && nums[k] == nums[k + 1])  k--;
                }
                else if (sum > target)  k--;
                else    j++;
            }
            while(i < n && nums[i] == curr)  i++;
        }
        return answers;
    }
};