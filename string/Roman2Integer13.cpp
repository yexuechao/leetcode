#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }
        map<char, int> ci_map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        int pre_sum = ci_map[s[0]];
        for (size_t i = 1; i < s.size(); i++) {
            if (ci_map[s[i]] > pre_sum) {
                sum -= pre_sum;
            } else {
                sum += pre_sum;
            }
            pre_sum = ci_map[s[i]];
        }
        sum += pre_sum;
        return sum;
    }
};