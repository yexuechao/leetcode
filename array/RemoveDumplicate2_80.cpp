#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int idx = 1;
        for (size_t cur = 1; cur < nums.size(); cur++) {
            // int now_idx = cur;
            if (nums[cur] == nums[cur - 1]) {
                cur++;
                while(cur < nums.size() && nums[cur] == nums[cur - 1]) {
                    cur++;
                }
                // 最后一位实际上不符合，需要回退
                cur--;
            }
            nums[idx] = nums[cur];
            idx++;

        }
        return idx;
    }
};