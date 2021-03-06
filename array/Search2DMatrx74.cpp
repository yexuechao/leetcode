class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int row = 0;
        int column = matrix[0].size() - 1;
        while(row >= 0 && row < matrix.size() && column >=0 && column < matrix[0].size()) {
            if (target == matrix[row][column]) {
                return true;
            } else if (target < matrix[row][column]) {
                column--;
            } else {
                row++;
            }
        }
        return false;
    }
};