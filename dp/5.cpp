class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int max_len = 1;
        string result = s.substr(0, 1);
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = s.size() - 1; j >= i; j--) {
                if (((j - i + 1) == 1 || (j - i + 1) == 2 || dp[i + 1][j - 1] == 1) && s[i] == s[j]) {
                    dp[i][j] = 1;
                }
                if (dp[i][j] == 1 && (j - i + 1) > max_len) {
                    result = s.substr(i, (j - i + 1));
                    max_len = j - i + 1;
                }
            }
        }
        return result;
    }
};