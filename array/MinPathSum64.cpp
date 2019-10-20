class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size(), 0));
        result[0][0] = grid[0][0];
        // 行
        for (size_t i = 1; i < grid[0].size(); i++) {
            result[0][i] = grid[0][i] + result[0][i - 1];
        }
        // 列
        for (size_t i = 1; i < grid.size(); i++) {
            result[i][0] = grid[i][0] + result[i - 1][0];
        }

        for (size_t i = 1; i < grid.size(); i++) {
            for(size_t j = 1; j < grid[0].size(); j++) {
                result[i][j] = (result[i - 1][j] > result[i][j - 1]) ? (result[i][j - 1] + grid[i][j]) : (result[i - 1][j] + grid[i][j]);
            }
        }
        return result[result.size() - 1][result[0].size() - 1];
    }
};