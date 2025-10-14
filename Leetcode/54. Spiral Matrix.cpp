class Solution {
public:
    vector<int> spiralTraversal;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;
        int c = 0, total_elements = m * n;
        while(spiralTraversal.size() != total_elements){
            if(c % 4 == 0){
                for(int i = left; i <= right; i++)  spiralTraversal.push_back(matrix[up][i]);
                up++;
            }
            else if(c % 4 == 1){
                for(int i = up; i <= down; i++)  spiralTraversal.push_back(matrix[i][right]);
                right--;
            }
            else if(c % 4 == 2){
                for(int i = right; i >= left; i--)  spiralTraversal.push_back(matrix[down][i]);
                down--;
            }
            else if(c % 4 == 3){
                for(int i = down; i >= up; i--)  spiralTraversal.push_back(matrix[i][left]);
                left++;
            }
            c++;
        }
        return spiralTraversal;
    }
};