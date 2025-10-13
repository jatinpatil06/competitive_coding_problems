class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void moveZeroes(vector<int>& nums) {
        /*
        Doing with O(n) extra space
        vector<int> non_zeros;
        int n = nums.size();
        int i;
        for(i = 0; i < n; i++)  if(nums[i] != 0)    non_zeros.push_back(nums[i]);
        for(i = 0; i < non_zeros.size(); i++)   nums[i] = non_zeros[i];
        for(; i < n; i++)   nums[i] = 0;
        */
        int last_zero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[last_zero]);
                last_zero++;
            }
        }
    }
};