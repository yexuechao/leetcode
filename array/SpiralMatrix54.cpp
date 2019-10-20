class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return vector<int>();
        }
        int top = 0;
        int bot = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> result;
        while (true) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            if (top > bot) {
                break;
            }
            for (int i = top; i <= bot; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            if (right < left) {
                break;
            }
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bot][i]);
            }
            bot--;
            if (bot < top) {
                break;
            }
            for (int i = bot; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
            if (left > right) {
                break;
            }
        }
        return result;
    }
};