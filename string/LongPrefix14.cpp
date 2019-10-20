#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string();
        }
        string result;
        // 取出最小长度
        int min_size = INT32_MIN;
        for (size_t i = 0; i < strs.size(); i++) {
            if (min_size > strs[i].size()) {
                min_size = strs[i].size();
            }
        }
        for (size_t i = 0; i < min_size; i++) {
            char target = strs[0][i];
            for (size_t j = 1; j < strs.size(); j++) {
                if (strs[j][i] != target) {
                    return result;
                }
            }
            result += target;
        }
        return result;
    }
};