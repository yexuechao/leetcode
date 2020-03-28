#include <vector>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        vector<int> results(s.size() + 1, 0);
        results[0] = 1;
        results[1] = 1; // s[0]
        for (int i = 2; i <= s.size(); i++) {
            // 前一个不能组合在一起的情况
            if (s[i - 1] == '0') {
                results[i] = results[i - 2];
            } else if (s[i - 2] == '0' || s[i - 2] >= '3') {
                results[i] = results[i - 1];
            } else if (s[i - 2] == 2) {
                // 如果s[i] <= 6 就可以组合在一起
                // = 0 也不能独立
                if (s[i - 1] <= 6) {
                    results[i] = results[i - 1] + results[i - 2];
                } else {
                    results[i] = results[i - 1];
                }
            } else {
                // s[i - 2] == 1
                results[i] = results[i - 1] + results[i - 2];
            }
        }
        return results.back();
    }
};