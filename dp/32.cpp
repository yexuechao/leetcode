#include "../define.h"
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        // s[i]表示以0结尾的括号匹配数，且s[i]一定要用上
        vector<int> dp(s.size() + 1, 0);
        int max_num = 0;
        for (int i = 2; i <= s.size(); i++) {
            // 三种情况
            // 如果当前是( 那没门
            // 如果)并且前一个是(，那么看dp[i - 2]
            // 如果前一个是)，第一个需要跟最前面的(搭配
            if (s[i - 1] == ')') {
                if (s[i - 2] == '(') {
                    dp[i] = dp[i - 2] + 2;
                } else if (i - 2 - dp[i - 1] >= 0 && s[i - 2 - dp[i - 1]] == '(') {
                    // s[i - 2] 对应的'('是 dp[i - 1]
                    dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
                }
            }

            max_num = max(max_num, dp[i]);
        }

        return max_num;
    }
};