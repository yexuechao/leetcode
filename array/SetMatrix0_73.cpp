class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 两个set 一个存行0 一个存列0
        if (matrix.empty()) {
            return ;
        }
        set<int> row;
        set<int> column;
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for (size_t i = 0; i < matrix.size(); i++) {
            if (row.find(i) != row.end()) {
                for (size_t j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (size_t i = 0; i < matrix[0].size(); i++) {
            if (column.find(i) != column.end()) {
                for (size_t j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        return ;
    }
};