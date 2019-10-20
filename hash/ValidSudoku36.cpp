#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() < 9 || board[0].size() < 9) {
            return false;
        }

        // 行
        for (size_t i = 0; i < 9; i++) {
            set<char> line;
            line.clear();
            for (size_t j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (line.find(board[i][j]) != line.end()) {
                    return false;
                } else {
                    line.insert(board[i][j]);
                }
            }
            line.clear();
        }

        // 列
        for (size_t i = 0; i < 9; i++) {
            set<char> line;
            for (size_t j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (line.find(board[j][i]) != line.end()) {
                    return false;
                } else {
                    line.insert(board[j][i]);
                }
            }
            line.clear();
        }

        // 九格
        for (size_t i = 0; i < 9; i += 3) {
            for (size_t j = 0; j < 9; j += 3) {
                // 表示第一个格 遍历内部九宫格
                set<char> nine;
                for (size_t i_inner = i; i_inner < i + 3; i_inner++) {
                    for (size_t j_inner = j; j_inner < j + 3; j_inner++) {
                        if (board[i_inner][j_inner] == '.') {
                            continue;
                        }
                        if (nine.find(board[i_inner][j_inner]) != nine.end()) {
                            return false;
                        } else {
                            nine.insert(board[i_inner][j_inner]);
                        }
                    }
                }
                nine.clear();
            }
        }
        return true;
    }
};