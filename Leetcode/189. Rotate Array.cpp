class Solution {
public:
    void reverse_arr(vector<int> &arr, int l, int r){
        while(l <= r){
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  //rotating multiple times doesnt make sense
        /*  Brute Force Approach
        for(int x = 0; x < k; x++){
            int last = nums[n - 1];
            for(int i = n - 1; i > 0; i--)  nums[i] = nums[i - 1];
            nums[0] = last;
        }
            A better approach would be to store the right halves elements in a temporary vector TC = O(N) & SC = O(N)
        vector<int> temp;
        for(int i = n - k; i < n; i++)  temp.push_back(nums[i]);
        for(int i = n - 1; i - k >= 0; i--) nums[i] = nums[i - k];
        for(int i = 0; i < k; i++)  nums[i] = temp[i];

            An optimal approach would be to reverse the arrays and rotate in place
        */
        reverse_arr(nums, 0, n - 1);
        reverse_arr(nums, 0, k - 1);
        reverse_arr(nums, k, n - 1);
    }
};