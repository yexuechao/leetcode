class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        vector<int> result;
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        int start = 0;
        while (row >= start * 2 && col >= start * 2) {
            spiralOrderCore(matrix, start, row - start, col - start, result);
            start++;
        }

        return result;
    }

    void spiralOrderCore(const vector<vector<int>>& matrix, int start, int row_end, int col_end, vector<int>& result) {
        int i = start;
        int j = start;
        // 向右
        while (j <= col_end) {
            result.push_back(matrix[i][j]);
            j++;
        }
        j--;
        i++;
        if (i > row_end) {
            return ;
        }
        // 向下
        while (i <= row_end) {
            result.push_back(matrix[i][j]);
            i++;
        }
        i--;
        j--;
        // 向左
        if (j < start) {
            return ;
        }
        while (j >= start) {
            result.push_back(matrix[i][j]);
            j--;
        }
        j++;
        i--;
        if (i <= start) {
            return ;
        }
        while(i > start) {
            result.push_back(matrix[i][j]);
            i--;
        }
        return ;
    }
};