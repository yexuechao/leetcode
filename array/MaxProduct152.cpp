class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<vector<int>> result(nums.size(), vector<int>(nums.size(), 0));
        // 打斜
        int max_num = INT_MIN;
        for (size_t i = 0; i < nums.size(); i++) {
            result[i][i] = nums[i];
            max_num = max(max_num, result[i][i]);
        }

        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                // i --> j
                result[i][j] = result[i][j - 1] * nums[j];
                max_num = max(max_num, result[i][j]);
            }
        }
        return max_num;
    }
};