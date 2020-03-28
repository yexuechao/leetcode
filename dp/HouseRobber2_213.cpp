#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(robCore(nums, 0, nums.size() - 1), robCore(nums, 1, nums.size()));

    }

    int robCore(vector<int>& nums, int head, int tail) {
        int result = nums[head];
        // 前 i 个
        vector<int> dp(nums.size() + 1, 0);
        // dp[0] = 1
        dp[head + 1] = nums[head];
        for (int i = head + 2; i <= tail; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            result = max(result, dp[i]);
        }
        return result;
    }
};