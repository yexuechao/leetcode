#include "../define.h"
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for(int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int p = j + 1;
                int q = nums.size() - 1;
                int tmp_target = target - nums[i] - nums[j];
                while(p < q) {
                    if ((p > j + 1 && nums[p] == nums[p - 1]) || nums[p] + nums[q] < tmp_target) {
                        p++;
                    } else if ((q < nums.size() - 1 && nums[q] == nums[q + 1]) || nums[p] + nums[q] > tmp_target) {
                        q--;
                    } else {
                        vector<int>  res{nums[i], nums[j], nums[p], nums[q]};
                        result.push_back(res);
                        p++;
                    }
                }
            }
        }
        return result;
    }
};