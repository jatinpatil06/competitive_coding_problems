class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /* Better Approach
        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > (nums.size() / 2))    return nums[i];
        }
        return -1;
        */
       //Optimal approach - Moore's Voting Algorithm
       int elem = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0)  elem = nums[i];
            nums[i] == elem ? count++ : count--;
        }
        if(count > 0){
            count = 0;
            for(int i = 0; i < nums.size(); i++)    if(nums[i] == elem) count++;
            if(count > nums.size() / 2) return elem;
        }
        return -1;
    }
};