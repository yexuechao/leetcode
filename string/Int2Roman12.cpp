#include <map>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        if (num <= 0 || num > 3999) {
            return string();
        }
        // map<char, int> ci_map{{'I', 1},\
        //                       {'V', 5},\
        //                       {'X', 10},\
        //                       {'L', 50},\
        //                       {'C', 100},\
        //                       {'D', 500},\
        //                       {'M', 1000}};
        map<int, string> is_map{{4, "IV"},\
                                {9, "IX"},\
                                {40, "XL"},\
                                {90, "XC"},\
                                {400, "CD"},\
                                {900, "CM"}};

        // 取各位数
        string result;
        // for (int i = 3; i >=1; i--) {

        // }
        int qian = num / 1000 % 10;
        for (int i = 0; i < qian; i++) {
            result += "M";
        }
        int bai = num / 100 % 10;
        if (is_map.find(bai * 100) != is_map.end()) {
            result += is_map[bai*100];
        } else {
            if (bai >= 5) {
                int dis = bai - 5;
                result += "D";
                for (int i = 0; i < dis; i++) {
                    result += "C";
                }
            } else {
                for (int i = 0; i < bai; i++) {
                    result += "C";
                }
            }
        }
        int shi = num / 10 % 10;
        if (is_map.find(shi * 10) != is_map.end()) {
            result += is_map[shi * 10];
        } else {
            if (shi >= 5) {
                int dis = shi - 5;
                result += "L";
                for (int i = 0; i < dis; i++) {
                    result += "X";
                }
            } else {
                for (int i = 0; i < shi; i++) {
                    result += "X";
                }
            }
        }

        int ge = num % 10;
        if (is_map.find(ge) != is_map.end()) {
            result += is_map[ge];
        } else {
            if (ge >= 5) {
                int dis = ge - 5;
                result += "V";
                for (int i = 0; i < dis; i++) {
                    result += "I";
                }
            } else {
                for (int i = 0; i < ge; i++) {
                    result += "I";
                }
            }
        }
        return result;
    }
};