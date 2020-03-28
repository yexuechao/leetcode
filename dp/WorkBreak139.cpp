#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }
        set<string> word_dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            bool flag = false;
            for (int j = 0; j < i; j++) {
                string tmp = s.substr(j, i - j);
                if (dp[j] == 1 && word_dict.find(tmp) != word_dict.end()) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                dp[i] = 1;
            }
        }
        return (dp[s.size()] == 1 ? true : false);
    }
};