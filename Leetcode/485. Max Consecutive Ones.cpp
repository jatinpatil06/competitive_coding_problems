class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len = 0, n = nums.size();
        /*  Brute force approach with TC = O(N ^ 2)
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && nums[j] == 1){
                max_len = max(j - i + 1, max_len);
                j++;
            }    
        }
            An efficient solution would be to use two pointers

        */
        int c = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)    c = 0;
            else{
                c++;
                max_len = max(max_len, c);
            }    
        }
        return max_len;
    }
};