class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() <= 1) {
            return vector<int>();
        }

        int x = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            x ^= nums[i];
        }
        x &= -x;
        vector<int> result(2, 0);
        for (size_t i = 0; i < nums.size(); i++) {
            if ((x & nums[i]) == x) {
                result[0] ^= nums[i];
            } else {
                result[1] ^= nums[i];
            }
        }
        return result;
    }
};