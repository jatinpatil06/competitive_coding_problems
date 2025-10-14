class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        /* Better Approach in SC = O(3n)
        vector<int> negatives, positives, answer;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) negatives.push_back(nums[i]);
            else    positives.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size() / 2; i++){
            answer.push_back(positives[i]);
            answer.push_back(negatives[i]);
        }
        return answer;
        */
        //We could try to do it in one pass with O(n) extra SC
        int i = 0, j = 0, n = nums.size();
        vector<int> answer(n);
        for(int k = 0; k < n; k+=2){
            while(i < n && nums[i] <= 0) i++;
            if(i < n)   answer[k] = nums[i];
            while(j < n && nums[j] > 0) j++;
            if(j < n)   answer[k + 1] = nums[j];
            i++;
            j++;
        }
        return answer;
    }
};