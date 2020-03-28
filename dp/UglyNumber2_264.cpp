#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1 || n > 1690) {
            return -1;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        // *2 *3 *5
        int idx = 1;
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;
        while(idx <= n - 1) {
            // 取最小
            dp[idx] = min(dp[idx2] * 2, dp[idx3] * 3);
            dp[idx] = min(dp[idx], dp[idx5] * 5);
            // 因为可能有重复的push_back进去，所以要去重
            if (dp[idx] >= dp[idx2] * 2) {
                idx2++;
            }
            if (dp[idx] >= dp[idx3] * 3) {
                idx3++;
            }
            if (dp[idx] >= dp[idx5] * 5) {
                idx5++;
            }
            idx++;
        }
        return dp.back();
    }
};