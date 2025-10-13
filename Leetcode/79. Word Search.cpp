class Solution {
public:
    bool isValid(int x, int y, vector<vector<char>> &board){
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '*')? true : false;
    }

    bool wordFind(vector<vector<char>> &board, int idx, string &word, int i, int j){
        if(idx == word.size() - 1 && word[idx] == board[i][j])  return true;
        char temp = board[i][j];
        board[i][j] = '*';
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int z = 0; z < 4; z++){
            int x = i + dx[z];
            int y = j + dy[z];
            if(isValid(x, y, board) && board[x][y] == word[idx + 1] && wordFind(board, idx + 1, word, x, y))    return true;
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0] && wordFind(board, 0, word, i, j))    return true;
        return false;
    }
};