class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return vector<string>();
        }
        // 要保证正确


    }
    void generateParenthesisCore(int n) {
        if (n >= h) {
            // 取到最后
            if (isCorrect(cur_res)) {
                result.push_back(cur_res);
            }
            return ;
        }

    }

    bool isCorrect(const string& str) {
        // 用栈来校验
        if (str.empty()) {
            return false;
        }
        stack<char> stack1;
        stack1.push_back(str[0]);
        size_t i = 1;
        for (i = 1; i < str.size(); i++) {
            char val = str[i];
            if (val == '(') {
                stack1.push_back(val);
            } else {
                char top = stack1.top();
                if (top == '(') {
                    stack1.pop_back();
                } else {
                    break;
                }
            }
        }
        if (!stack1.empty() || i < str.size()) {
            return false;
        }
        return true;
    }

    int h;
    vector<string> result;
    string cur_res;
};