class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        // 包含nums[i]的
        int max_num = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_num = max(dp[i], max_num);
                }
            }
        }
        return max_num;
    }
};