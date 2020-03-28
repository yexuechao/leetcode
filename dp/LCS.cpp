#include "../define.h"
class Solution {
public:
    int findLCS(string str1, int n, string str2, int m) {
        if (str1.empty() || str2.empty()) {
		    return 0;
        }
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

        for (int i = 1; i < str1.size(); i++) {
            for (int j = 1; j < str2.size(); j++) {
                // dp[i][j] =
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string result = LCSRes(str1, str2, dp);
        cout << result;
        return dp[n][m];
    }
    string LCSRes(const string& str1, const string& str2, const vector<vector<int>>& dp) {
        if (dp.empty() || dp[0].empty()) {
            return "";
        }
        // "1A2C3D4B56",10,"B1D23CA45B6A",12
        string result;
        int i = dp.size() - 1;
        int j = dp[0].size() - 1;
        while (i >= 1 && j >= 1) {
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};