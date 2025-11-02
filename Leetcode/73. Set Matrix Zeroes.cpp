class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        Better Approach with SC = O(m + n)
        unordered_set<int> rows, columns;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    columns.insert(j);
                }
        
        for(auto row : rows)
            for(int j = 0; j < n; j++)  matrix[row][j] = 0;

        for(auto column : columns)
            for(int i = 0; i < m; i++)  matrix[i][column] = 0;
    }

    An optimal approach with SC = O(1)
    */
        int m = matrix.size(), n = matrix[0].size();
        int col1 = 1;
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) col1 = 0;

        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        
        //Setting all the inner cells
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
            }
        }

        if(matrix[0][0] == 0)   for(int j = 1; j < n; j++)  matrix[0][j] = 0;
        if(col1 == 0)   for(int i = 0; i < m; i++)  matrix[i][0] = 0;
    }
};