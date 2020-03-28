class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while(n != 0) {
            result++;
            n = n & (n - 1);
        }
        return result;
    }

    // 1100
    // 1011
};