#include<string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) {
            return string();
        }
        string result = "0";
        for (int i = num1.size() - 1; i >=0; i--) {
            string tmp;
            int forward = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                // 3 * 456
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int cur = n1 * n2 + forward;
                forward = cur / 10;
                tmp += to_string(cur % 10);
            }
            if (forward != 0) {
                tmp += to_string(forward);
            }
            reverse(tmp.begin(), tmp.end());
            if (tmp.empty() || tmp[0] == '0') {
                continue;
            }
            int dis = num1.size() - i - 1;
            for (int i = 0; i < dis; i++) {
                tmp += "0";
            }
            result = plus(result, tmp);
        }
        return result;
    }
    string plus(string num1, string num2) {
        if (num1.empty() || num2.empty()) {
            return string();
        }
        int idx1 = num1.size() - 1;
        int idx2 = num2.size() - 1;
        string result;
        int forward = 0;
        while(idx1 >= 0 || idx2 >= 0) {
            int n1 = (idx1 >= 0 ? (num1[idx1] - '0') : 0);
            int n2 = (idx2 >= 0 ? (num2[idx2] - '0') : 0);
            int cur = n1 + n2 + forward;
            forward = cur / 10;
            result += to_string(cur % 10);
            idx1--;
            idx2--;
        }
        if (forward != 0) {
            result += to_string(forward);
        }
        // 翻转 result
        reverse(result.begin(), result.end());
        return result;
    }
};