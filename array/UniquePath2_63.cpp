class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) {
            return 0;
        }
        vector<vector<long>> result(obstacleGrid.size(), vector<long>(obstacleGrid[0].size(), 0));
        // 第一行
        result[0][0] = 1;
        for (size_t i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            result[0][i] = 1;
        }
        for(size_t i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            result[i][0] = 1;
        }
        for(size_t i = 1; i < obstacleGrid.size(); i++) {
            for (size_t j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1) {
                    result[i][j] = 0;
                } else {
                    result[i][j] = result[i - 1][j] + result[i][j - 1];
                }
            }
        }
        return result[result.size() - 1][result[0].size() - 1];
    }
    void uniquePathsWithObstaclesCore(vector<vector<int>>& obstacleGrid, int row, int column) {
        if (row >= obstacleGrid.size() || column >= obstacleGrid[0].size()) {
            return ;
        }
        if (obstacleGrid[row][column] == 1) {
            return ;
        }
        if (row == obstacleGrid.size() - 1 && column == obstacleGrid[0].size() - 1) {
            sum++;
            return ;
        }
        // 往下走
        uniquePathsWithObstaclesCore(obstacleGrid, row + 1, column);
        //往右走
        uniquePathsWithObstaclesCore(obstacleGrid, row, column + 1);
        return ;
    }
        // uniquePathsWithObstaclesCore(obstacleGrid, 0, 0);
        // return sum;
    int sum;
};