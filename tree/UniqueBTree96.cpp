#include "../define.h"
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) {
            return n;
        }
        // G(n): n 个节点存在的二叉排序树个数
        // f(n): 以为i为跟的二叉排序树个数
        // G(n) = f(1) + f(2) + ... + f(n)
        // 以i为根，左子树节点个数i - 1，右子树节点为 n - i
        // f(i) = G(i - 1) * G(n - i)
        // G(n) = G(0) * G(n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            // G(i) = G(0) * G(i - 1) + ... + G(i - 1) * G(0)
            // G(2) = G(0) * G(1) + G(1) * G(0)
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }

};