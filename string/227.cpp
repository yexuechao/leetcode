#include "../define.h"
class Solution {
public:
    int calculate(string s) {
        if (s.empty()) {
            return 0;
        }
        stack<char> symbol;
        vector<string> nums;
        for (int i = 0; i < s.size(); i++) {
            if (IsDigit(s[i])){
                int start = i;
                i++;
                while(i < s.size() && IsDigit(s[i])) {
                    i++;
                }
                i--;
                string tmp = s.substr(start, i - start + 1);
                nums.push_back(tmp);
            } else {
                // 符号
                if (s[i] == '/' || s[i] == '*') {
                    while(!symbol.empty()) {
                        char top = symbol.top();
                        if (top == '/' || top == '*') {
                            string tmp;
                            tmp += top;
                            nums.push_back(tmp);
                            symbol.pop();
                        } else {
                            break;
                        }
                    }
                    symbol.push(s[i]);
                } else {
                    while(!symbol.empty()) {
                        char top = symbol.top();
                        string tmp;
                        tmp += top;
                        nums.push_back(tmp);
                        symbol.pop();
                    }
                    symbol.push(s[i]);
                }
            }
        }
        while(!symbol.empty()) {
            char top = symbol.top();
            string tmp;
            tmp += top;
            nums.push_back(tmp);
            symbol.pop();
        }
        stack<string> calc;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == "/" || nums[i] == "*" || nums[i] == "+" || nums[i] == "-") {
                if (calc.size() < 2) {
                    return 0;
                }
                string num1_s = calc.top();
                int num1 = atoi(num1_s.c_str());
                calc.pop();
                string num2_s = calc.top();
                int num2 = atoi(num2_s.c_str());
                calc.pop();
                int res = Calc(num2, num1, nums[i]);
                string s_res = to_string(res);
                calc.push(s_res);
            } else {
                calc.push(nums[i]);
            }
        }
        string final_res = calc.top();
        int final_n = atoi(final_res.c_str());
        return final_n;
    }

    int Calc(int num1, int num2, string symbol) {
        int result = 0;
        if (symbol == "+") {
            result = num1 + num2;
        } else if (symbol == "-") {
            result = num1 - num2;
        } else if (symbol == "*") {
            result = num1 * num2;
        } else {
            result = num1 / num2;
        }
        return result;
    }

    bool IsDigit(char num) {
        if (num >= '0' && num <= '9') {
            return true;
        }
        return false;
    }
};