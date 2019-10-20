class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        int sum = 0;
        for (size_t i = 0; i < size; i++) {
            sum ^= nums[i];
            sum ^= i;
        }
        sum ^= size;
        return sum;
    }
};