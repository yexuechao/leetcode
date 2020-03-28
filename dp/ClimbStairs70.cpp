class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int h1 = 1;
        int h2 = 2;
        for (int i = 3; i <= n; i++) {
            int cur = h1 + h2;
            h1 = h2;
            h2 = cur;
        }
        return h2;
    }
};