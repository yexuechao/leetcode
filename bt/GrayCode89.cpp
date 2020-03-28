class Solution {
public:
    vector<int> grayCode(int n) {
        if (n < 0) {
            return vector<int>();
        }
        vector<int> result;
        result.push_back(0);
        // 2的n - 1 次方 - 1
        int head = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = result.size() - 1; j>= 0; j--) {
                result.push_back(head + result[j]);
            }
            head <<= 1;
        }
        return result;
    }
};