class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) {
            return true;
        }
        if (board.empty()) {
            if (word.empty()) {
                return true;
            }
            return false;
        }
        block = vector(board.size(), vector<int>(board[0].size()));
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }
                if (ExistCore(board, word, 0, i, j) == true) {
                    return true;
                }
            }
        }
        return false;
    }
    bool ExistCore(vector<vector<char>>& board, string word, int h, int row, int column) {
        if (row >= board.size() || column >= board[0].size()) {
            return false;
        }
        if (h == word.size() - 1 && board[row][column] == word[h] && block[row][column] == 0) {
            return true;
        }
        if (board[row][column] != word[h] || block[row][column] == 1) {
            return false;
        }
        block[row][column] = 1;
        if (ExistCore(board, word, h + 1, row - 1, column) ||\
            ExistCore(board, word, h + 1, row + 1, column) ||\
            ExistCore(board, word, h + 1, row, column - 1) ||\
            ExistCore(board, word, h + 1, row, column + 1)) {
            return true;
        }
        block[row][column] = 0;
        return false;
    }
    vector<vector<int>> block;
};