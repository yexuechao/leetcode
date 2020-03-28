#include "../define.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        // 求 dp[0] 最小值
        for (int i = nums.size() - 2; i >= 0; i--) {
            // nums.size() - 2 ---> nums.size() - 1
            int min_num = INT_MAX;
            for (int j = nums[i]; j >= 1; j--) {
                if (j + i >= nums.size() - 1) {
                    min_num = 1;
                    break;
                }
                if (nums[i + j] == 0) {
                    continue;
                }
                if (dp[i + j] == INT_MAX) {
                    continue;
                }
                min_num = min(1 + dp[i + j], min_num);
            }
            dp[i] = min_num;
        }
        return dp[0];
    }
};