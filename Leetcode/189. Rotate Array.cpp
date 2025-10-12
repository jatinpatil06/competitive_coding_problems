class Solution {
public:
    void swap(int &a, int &b){
        int temp = b;
        b = a;
        a = temp;
    }
    void rotate(vector<int>& nums, int k) {
        /*
        Brute Force Method
        int n = nums.size();
        k = k % n;
        for(int j = 0; j < k; j++){
            int last = nums[n - 1];
            for(int i = n - 1; i >= 1; i--) nums[i] = nums[i - 1];
            nums[0] = last;
        }
        */
        int n = nums.size();
        k = k % n;
        int i, j;
        i = 0;
        j = n - 1;
        while(i <= j)   swap(nums[i++], nums[j--]);
        i = 0;
        j = k - 1;
        while(i <= j)   swap(nums[i++], nums[j--]);
        i = k;
        j = n - 1;
        while(i <= j)   swap(nums[i++], nums[j--]);
    }
};