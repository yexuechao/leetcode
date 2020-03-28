class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int max_num = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        // 给第一行和第一列赋值
        for (size_t i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            max_num = max(dp[i][0], max_num);
        }
        for (size_t j = 0; j < matrix[0].size(); j++) {
            dp[0][j] = matrix[0][j] - '0';
            max_num = max(dp[0][j], max_num);
        }
        for (size_t i = 1; i < matrix.size(); i++) {
            for (size_t j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    dp[i][j] += 1;
                    max_num = max(dp[i][j], max_num);
                }
            }
        }
        return (max_num * max_num);
    }
};