class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        int N = n;
        if (N < 0) {
            N = -N;
            x = 1 / x;
        }
        return fastPow(x, n);
    }

    double fastPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            // 偶数
            return half * half;
        } else {
            return half * half * x;
        }
    }
};