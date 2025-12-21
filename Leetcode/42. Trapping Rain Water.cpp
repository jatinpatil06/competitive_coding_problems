class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, n = height.size();
        /*  Brute Force approach with TC = O(N ^ 2)
        for(int i = 0; i < n; i++){
            int curr_height = height[i];
            //find max height on the left side
            int left_max = height[i], left = i - 1;
            while(left >= 0){
                left_max = max(height[left], left_max);
                left--;
            }
            //find max height on the right side
            int right_max = height[i], right = i + 1;
            while(right < n){
                right_max = max(height[right], right_max);
                right++;
            }
            if(left_max != height[i] && right_max != height[i]){
                water += min(left_max, right_max) - curr_height;
            }
        }

            To linearize this with TC = O(N), we will precompute the maximum heights for each bar on both the LHS and RHS
        */
        vector<int> left_max(n), right_max(n);
        int max_height = height[0];
        left_max[0] = 0;
        for(int i = 1; i < n; i++){
            left_max[i] = max_height;
            max_height = max(max_height, height[i]);
        }
        max_height = height[n - 1];
        right_max[n - 1] = 0;
        for(int i = n - 1; i >= 0; i--){
            right_max[i] = max_height;
            max_height = max(max_height, height[i]);
        }
        for(int i = 0; i < n; i++){
            int max_height_avl = min(left_max[i], right_max[i]);
            if(max_height_avl > height[i])  water += max_height_avl - height[i];
        }
        return water;
    }
};