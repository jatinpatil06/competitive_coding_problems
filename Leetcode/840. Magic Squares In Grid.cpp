class Solution {
public:
    bool check(int i, int j, vector<vector<int>> &grid){
        unordered_map<int, int> row_sum, col_sum, diag_sum, nums;
        for(int row = i; row < i + 3; row++){
            for(int col = j; col < j + 3; col++){
                int curr = grid[row][col];
                int r = row - i;
                int c = col - j;
                if(curr == 0 || curr >= 10 || (nums.find(curr) != nums.end())) return false;
                nums[curr] = 1;
                row_sum[r] += curr;
                col_sum[c] += curr;
                if(r == c)  diag_sum[0] += curr;
                if(r + c == 2)  diag_sum[1] += curr;
            }
        }
        int init_sum = row_sum[0];
        for(int i = 0; i < 3; i++)  if(init_sum != row_sum[i])  return false;
        for(int i = 0; i < 3; i++)  if(init_sum !=col_sum[i])  return false;
        for(int i = 0; i < 2; i++)  if(init_sum != diag_sum[i])  return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for(int i = 0; i <= m - 3; i++){
            for(int j = 0; j <= n - 3; j++){
                if(check(i, j, grid))   count++;
            }
        }
        return count;
    }
};