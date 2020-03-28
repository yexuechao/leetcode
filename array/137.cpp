#include "../define.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int64_t x = 1;
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bits = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & x) != 0) {
                    bits++;
                }
            }
            if (bits % 3 != 0) {
                result += x;
            }

            x <<= 1;
        }

        return result;
    }
};