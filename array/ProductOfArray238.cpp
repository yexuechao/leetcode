class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        // 有更加优化的写法
        vector<int> pre(nums.size(), 1);
        vector<int> after(nums.size(), 1);
        pre[0] = nums[0];
        after[nums.size() - 1] = nums.back();
        for (size_t i = 1; i < nums.size(); i++) {
            pre[i] = pre[i - 1] * nums[i];
            after[nums.size() - i - 1] = after[nums.size() - i] * nums[nums.size() - i - 1];
        }
        vector<int> result(nums.size(), 1);
        result[0] = after[1];
        result[nums.size() - 1] = pre[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++) {
            result[i] = pre[i - 1] * after[i + 1];
        }
        return result;
    }
};