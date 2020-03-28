#include<iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 只有一个 1 或者是 0
        if (n <= 0) {
            return false;
        }
        uint32_t N = n;
        cout << N;
        N = N & (N - 1);
        return (0 == N);
    }
};