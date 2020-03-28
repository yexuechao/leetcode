#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 统计每一位是否是1
        if(nums.empty()) {
            return 0;
        }
        int64_t x = 1;
        vector<int> tmp(32, 0);
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & x) != 0) {
                    tmp[i]++;
                }
            }
            x <<= 1;
        }
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            result <<= 1;
            result += tmp[i] % 3;
        }
        return result;
    }
};