#include "../define.h"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int max_num = nums[0];
        int min_num = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int cur_max = max(max_num * nums[i], min_num * nums[i]);
            cur_max = max(cur_max, nums[i]);
            int cur_min = min(max_num * nums[i], min_num * nums[i]);
            cur_min = min(cur_min, nums[i]);
            result = max(cur_max, result);
            min_num = cur_min;
            max_num = cur_max;
        }
        return result;
    }
};