class Solution {
public:
    int myAtoi(string str) {
        str = trim(str);
        if (str.empty()) {
            return 0;
        }
        bool positive = true;
        // 先取出符号
        int idx = 0;
        if (str[idx] == '+' || str[idx] == '-') {

            if (str.size() <= 1) {
                return 0;
            }
            if (str[idx] == '-') {
                positive = false;
            }
            idx++;
        }
        if (!isdigit(str[idx])) {
            return 0;
        }
        // 必须是数字
        int64_t result = 0;
        for (size_t i = idx; i < str.size(); i++) {
            if (!isdigit(str[i])) {
                break;
            }
            int val = str[i] - '0';
            result *= 10;
            result += val;
            // 大小判断
            if (positive) {
                if (result > INT_MAX) {
                    return INT_MAX;
                }
            } else {
                if (-result < INT_MIN) {
                    return INT_MIN;
                }
            }
        }
        result *= (positive ? 1 : -1);
        return result;
    }
    string trim(const string& str) {
        string::size_type pos = str.find_first_not_of(' ');
        if (pos == string::npos)
        {
            return str;
        }
        string::size_type pos2 = str.find_last_not_of(' ');
        if (pos2 != string::npos)
        {
            return str.substr(pos, pos2 - pos + 1);
        }
        return str.substr(pos);
    }
};