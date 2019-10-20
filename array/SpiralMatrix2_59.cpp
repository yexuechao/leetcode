class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return vector<vector<int>>();
        }
        // int sum = n * n;
        vector<vector<int>> result(n, vector<int>(n, 0));
        int top = 0;
        int bot = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;
        while (true) {
            for (int i = left; i <= right; i++) {
                result[top][i] = num;
                num++;
            }
            top++;
            if (top > bot) {
                break;
            }
            for (int i = top; i <= bot; i++) {
                result[i][right] = num;
                num++;
            }
            right--;
            if (right < left) {
                break;
            }
            for (int i = right; i >= left; i--) {
                result[bot][i] = num;
                num++;
            }
            bot--;
            if (bot < top) {
                break;
            }
            for (int i = bot; i >= top; i--) {
                result[i][left] = num;
                num++;
            }
            left++;
            if (left > right) {
                break;
            }
        }
        return result;
    }
};