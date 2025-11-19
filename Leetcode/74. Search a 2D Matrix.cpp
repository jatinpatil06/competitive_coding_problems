class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        /*  Brute Force approach with TC = )(N ^ 2)
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == target)  return true;

        An optimal would be to use binary search
        1) find the largest element in the first column <= target
        2) find the target in the corresponding row
        */

        int row = 0;
        int low = 0, high = m - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(matrix[mid][0] <= target){
                row = mid;
                low = mid + 1;
            }
            else    high = mid - 1;
        }
        low = 0, high = n - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            if(matrix[row][mid] == target)  return true;
            if(matrix[row][mid] > target)   high = mid - 1;
            else    low = mid + 1;
        }
        return false;
    }
};