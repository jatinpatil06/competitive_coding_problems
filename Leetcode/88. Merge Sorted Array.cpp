class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
            A brute force approach would be to create a new array which would be filled in a sorted fashion using nums1 and num2. This sorted array would be copied into nums1.
            An optimal approach to merge the two arrays in place with TC = O(m + n)
        */
        int i = m - 1, j = n - 1, k = nums1.size() - 1;
        while(i >= 0  && j >= 0){
            if(nums2[j] >= nums1[i])    nums1[k--] = nums2[j--];
            else    nums1[k--] = nums1[i--];
        }
        while(j >= 0)   nums1[k--] = nums2[j--];
    }
};