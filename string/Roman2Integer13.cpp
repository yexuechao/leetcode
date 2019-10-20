#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> ci_map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if ((s[i] != 'I' && s[i] != 'X' && s[i] != 'C') || i == s.size() - 1) {
                sum += ci_map[s[i]];
            } else {
                if (s[i] == 'I') {
                    if (s[i + 1] == 'V') {
                        sum += 4;
                        i++;
                    } else if (s[i + 1] == 'X') {
                        sum += 9;
                        i++;
                    } else {
                        sum += 1;
                    }
                } else if (s[i] == 'X') {
                    if (s[i + 1] == 'L') {
                        sum += 40;
                        i++;
                    } else if(s[i + 1] == 'C') {
                        sum += 90;
                        i++;
                    } else {
                        sum += 10;
                    }
                } else if (s[i] == 'C') {
                    if (s[i + 1] == 'D') {
                        sum += 400;
                        i++;
                    } else if (s[i + 1] == 'M') {
                        sum += 900;
                        i++;
                    } else {
                        sum += 100;
                    }
                }
            }
        }
        return sum;
    }
};