class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return ;
        }
        int size = matrix.size();
        for (size_t i = 0; i < size / 2; i++) {
            for (size_t j = 0 ; j < size; j++){
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        for (size_t i = 0; i < size; i++) {
            for (size_t j = i; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        return ;
    }
};