class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return ;
        }
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                CheckLoc(board, i, j);
            }
        }
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == -2) {
                    board[i][j] = 1;
                }
            }
        }
        return ;
    }

    void CheckLoc(vector<vector<int>>& board, int row, int column) {
        int left = column > 0 ? (column - 1) : 0;
        int right = column < board[0].size() - 1 ? (column + 1) : (board[0].size() - 1);
        int top = row > 0 ? (row -1) : 0;
        int bot = row < board.size() - 1 ? (row + 1) : (board.size() - 1);

        int count = 0;
        for (int i = top; i <= bot; i++) {
            for (int j = left; j <= right; j++) {
                if (board[i][j] == 1 || board[i][j] == -1) {
                    count++;
                }
            }
        }
        if (board[row][column] == 0) {
            if (count == 3) {
                board[row][column] = -2;
            }
        } else {
            if (count <= 2 || count >= 5) {
                board[row][column] = -1;
            } else if (count == 3 || count == 4) {
                board[row][column] = 1;
            }
        }
        return ;
    }
};