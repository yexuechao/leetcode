#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }
        string str = s;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        // 只考虑字母和数字
        int head = 0;
        int tail = str.size() - 1;
        while(head < tail) {
            while(!isdigit(str[head]) && !isalpha(str[head]) && head <= tail) {
                head++;
            }
            while(!isdigit(str[tail]) && !isalpha(str[tail]) && head <= tail) {
                tail--;
            }

            if (head > tail) {
                // if (tail == str.size() - 1) {
                //     return true;
                // }
                return true;
            }
            if (str[head] != str[tail]) {
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
};