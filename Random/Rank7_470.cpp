// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int num = 0;
        while(1) {
            // 产生 1--49 都非常公平
            // 也就是 1 -- 40 都非常公平
            num = (rand7() - 1) * 7 + rand7();
            if (41 <= num) {
                continue;
            }
            break;
        }
        return (num % 10) + 1;
    }
};