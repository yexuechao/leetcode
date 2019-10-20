class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return false;
        }
        // val idx
        unordered_map<int, int> num2idx;
        for (size_t i = 0; i < nums.size(); i++) {
            if (num2idx.find(nums[i]) == num2idx.end()) {
                num2idx[nums[i]] = i;
            } else {
                if (i - num2idx[nums[i]] <= k) {
                    return true;
                } else {
                    num2idx[nums[i]] = i;
                }
            }
        }
        return false;
    }
};