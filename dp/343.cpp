#include "../define.h"
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 2) {
            return 1;
        }
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            int max_idx = i / 2;

            for (int j = 1; j <= max_idx; j++) {
                if (dp[j] * dp[i - j] > dp[i]) {
                    dp[i] = dp[j] * dp[i - j];
                }
                // 只拆分成两个
                if (dp[j] * (i - j) > dp[i]) {
                    dp[i] = dp[j] * (i - j);
                }
                if (j * dp[i - j] > dp[i]) {
                    dp[i] = j * dp[i - j];
                }
                if (j * (i - j) > dp[i]) {
                    dp[i] = j * (i - j);
                }
            }
        }

        return dp[n];
    }
};