class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int res = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return ret;
    }
};