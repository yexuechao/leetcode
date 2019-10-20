#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 0 || s.empty()) {
            return string();
        }
        if (numRows == 1) {
            return s;
        }
        vector<string> strs(min(numRows, int(s.size())));
        int curRow = 0;
        bool down = false;
        for (size_t i = 0; i < s.size(); i++) {
            strs[curRow] += s[i];
            if (curRow == 0 || curRow == strs.size() - 1) {
                down = !down;
            }
            curRow += (down ? 1 : -1);
        }
        string result;
        for (size_t i = 0; i < strs.size(); i++) {
            result += strs[i];
        }
        return result;
    }
};