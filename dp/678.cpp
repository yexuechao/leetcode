#include "../define.h"
class Solution {
public:
    bool checkValidString(string s) {
        if (s.empty()) {
            return true;
        }
        vector<char> sc;
        return checkValidStringCore(s, sc, 0);
    }

    bool checkValidStringCore(string s, vector<char>& sc, int h) {
        PrintVector(sc);
        if (h == s.size() && sc.empty()) {
            return true;
        }
        if (h >= s.size()) {
            return false;
        }
        if (s[h] == '(') {
            sc.push_back(s[h]);
            if (checkValidStringCore(s, sc, h + 1)) {
                return true;
            }
            sc.pop_back();
            return false;
        } else if (s[h] == ')') {
            if (sc.empty()) {
                return false;
            }
            char top = sc.back();
            if (top != '(') {
                return false;
            }
            sc.pop_back();
            if (checkValidStringCore(s, sc, h + 1)) {
                return true;
            }
            sc.push_back('(');
            return false;
        }
        // == *
        // 加 )
        if (!sc.empty()) {
            char top = sc.back();
            if (top == '(') {
                // 这种情况下才可以加)
                sc.pop_back();
                bool right = checkValidStringCore(s, sc, h + 1);
                sc.push_back('(');
                if (right == true) {
                    return true;
                }
            }
        }
        sc.push_back('(');
        bool left = checkValidStringCore(s, sc, h + 1);
        sc.pop_back();
        if (left == true) {
            return true;
        }
        bool emp = checkValidStringCore(s, sc, h + 1);
        if (emp == true) {
            return true;
        }
        return false;
    }

    void PrintVector(vector<char> arr) {
        for (auto v:arr) {
            cout << v;
        }
        cout << "\n";
    }

};