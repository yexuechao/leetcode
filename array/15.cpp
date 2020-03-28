#include "../define.h"
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums.back() < 0) {
            return {};
        }
        // 开始遍历
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = 0 - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                if (nums[j] > target) {
                    break;
                } else if ((j > i + 1 && nums[j - 1] == nums[j]) || nums[j] + nums[k] < target) {
                    ++j;
                } else if ((k < nums.size() - 1 && nums[k + 1] == nums[k]) || nums[j] + nums[k] > target) {
                    --k;
                } else {
                    // 找到一个
                    vector<int> res{nums[i], nums[j], nums[k]};
                    result.push_back(res);
                    ++j;
                }
            }
        }
        return result;
    }
};