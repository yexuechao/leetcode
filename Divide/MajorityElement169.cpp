class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int num = nums[0];
        int count = 1;
        for(size_t i = 1; i < nums.size(); i++) {
            if (num == nums[i]) {
                count++;
            } else {
                count--;
                if (count < 0) {
                    num = nums[i];
                    count = 1;
                }
            }
        }
        return num;
    }
};