class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return result;
        }
        SubsetsCore(nums, 0);
        return result;
    }
    void SubsetsCore(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            result.push_back(cur);
            return ;
        }
        // 取或者不取
        SubsetsCore(nums, idx + 1);
        cur.push_back(nums[idx]);
        SubsetsCore(nums, idx + 1);
        cur.pop_back();
        return ;
    }
    vector<vector<int>> result;
    vector<int> cur;
};