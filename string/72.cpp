class Solution {
public:
        int minDistance(string word1, string word2) {
            if (word1.empty()) {
                return word2.size();
            }
            if (word2.empty()) {
                return word1.size();
            }
            // word1-->word2
            vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
            for (int i = 1; i <= word1.size(); i++) {
                dp[i][0] = i;
            }

            for (int i = 1; i <= word2.size(); i++) {
                dp[0][i] = i;
            }

            for (int i = 1; i <= word1.size(); i++) {
                for (int j = 1; j <= word2.size(); j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        // 增加 dp[i][j - 1]
                        // 删除 dp[i - 1][j]
                        // 替换 dp[i - 1][j - 1]
                        dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                        dp[i][j] += 1;
                    }
                }
            }

            return dp[word1.size()][word2.size()];
        }
};