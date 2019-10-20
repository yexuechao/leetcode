class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        unordered_set<int> i_s;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i_s.find(nums[i]) != i_s.end()) {
                return true;
            }
            i_s.insert(nums[i]);
        }
        return false;
    }
};