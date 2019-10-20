#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        if (s.empty()) {
            return 0;
        }
        // 中缀改成后缀
        vector<string> nums;
        stack<char> symbol;
        for (size_t i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                // 获取多位
                int idx = i;
                while(idx < s.size() && isdigit(s[idx])) {
                    idx++;
                }
                string tmp = s.substr(i, idx - i);
                nums.push_back(tmp);
                i = idx - 1;
            } else {
                if (s[i] == '/' || s[i] == '*') {
                    while (!symbol.empty() &&\
                           (symbol.top() == '/' || symbol.top() == '*')) {
                        char tmp_c = symbol.top();
                        symbol.pop();
                        string str;
                        str += tmp_c;
                        nums.push_back(str);
                    }
                    symbol.push(s[i]);
                } else if (s[i] == '+' || s[i] == '-') {
                    while(!symbol.empty()) {
                        char tmp_c = symbol.top();
                        symbol.pop();
                        string str;
                        str += tmp_c;
                        nums.push_back(str);
                    }
                    symbol.push(s[i]);
                }
            }
        }
        while(!symbol.empty()) {
            char tmp_c = symbol.top();
            symbol.pop();
            string str;
            str += tmp_c;
            nums.push_back(str);
        }
        // 计算后缀
        stack<int> result_stack;
        for (size_t i = 0; i < nums.size(); i++) {
            if (IsNum(nums[i])) {
                int num = atoi(nums[i].c_str());
                result_stack.push(num);
            } else {
                // 弹出来两个
                int n1 = result_stack.top();
                result_stack.pop();
                int n2 = result_stack.top();
                result_stack.pop();
                int sum = CalcCore(n1, n2, nums[i]);
                result_stack.push(sum);
            }
        }
        int sum = result_stack.top();
        return sum;
    }

    int CalcCore(int n1, int n2, string symbol) {
        switch(symbol[0]) {
            case '+': {
                return n1 + n2;
            }
            break;
            case '-': {
                return n2 - n1;
            }
            break;
            case '*': {
                return n1 * n2;
            }
            break;
            case '/': {
                return n2/n1;
            }
            break;
        }
        return 0;
    }
    bool IsNum(string str) {
        if (str.empty()) {
            return false;
        }
        for (size_t i = 0; i < str.size(); i++) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }
};