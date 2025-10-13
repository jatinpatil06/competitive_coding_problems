class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    bool check(vector<int>& nums) {
        //First, we will unrotate the array, then check whether it is sorted or not
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                int l = 0, r = i;
                while(l <= r)   swap(nums[l++], nums[r--]);
                l = i + 1, r = nums.size() - 1;
                while(l <= r)   swap(nums[l++], nums[r--]);
                l = 0, r = nums.size() - 1;
                while(l <= r)   swap(nums[l++], nums[r--]);
                break;
            }
        }
        for(int i = 0; i < nums.size() - 1; i++) if(nums[i] > nums[i + 1]) return false;
        return true;
    }
};