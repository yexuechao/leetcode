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
        results[1] = 1;
        for (int i = 2; i <= s.size(); i++) {
            if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2]== '2') {
                    results[i] = results[i - 2];
                } else {
                    return 0;
                }
            } else if (s[i - 2] == '1') {
                results[i] = results[i - 1] + results[i - 2];
            } else if (s[i - 2] == '2') {
                if (s[i - 1] <= '6' && s[i - 1] >= '1') {
                    results[i] = results[i - 1] + results[i - 2];
                } else {
                    results[i] = results[i - 1];
                }
            } else {
                results[i] = results[i - 1];
            }
        }
        return results.back();
    }
};