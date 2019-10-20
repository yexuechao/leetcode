#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return string();
        }
        if (numerator == 0) {
            return string("0");
        }
        // 正负
        bool is_plus = true;
        if (numerator < 0 ^ denominator < 0) {
            is_plus = false;
        }
        int64_t num = static_cast<int64_t>(numerator);
        int64_t denom = static_cast<int64_t>(denominator);
        num = abs(num);
        denom = abs(denom);
        // 整数部分
        int64_t part_int = num / denom;
        // 小数部分
        num %= denom;
        unordered_map<int64_t, int> u_map;
        int idx = 0;
        vector<int> nums;
        string res;
        if (!is_plus) {
            res += "-";
        }
        res += to_string(part_int);
        if (num != 0) {
            res += ".";
        }
        while(num != 0 && u_map.find(num) == u_map.end()) {
            u_map[num] = idx;
            idx++;
            num *= 10;
            int64_t val = num / denom;
            nums.push_back(val);
            num %= denom;
        }

        if (u_map.find(num) != u_map.end()) {
            for (size_t i = 0; i < u_map[num]; i++) {
                string num_s = to_string(nums[i]);
                res.push_back(num_s[0]);
            }
            res.push_back('(');
            for (size_t i = u_map[num]; i < nums.size(); i++) {
                string num_s = to_string(nums[i]);
                res.push_back(num_s[0]);
            }
            res.push_back(')');

        } else {
            // num == 0
            for (size_t i = 0; i < nums.size(); i++) {
                string num_s = to_string(nums[i]);
                res.push_back(num_s[0]);
            }
        }
        return res;
    }
};