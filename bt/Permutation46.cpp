class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return results;
        }
        permuteCore(nums, 0);
        return results;
    }
    void permuteCore(vector<int>& nums, int h) {
        if (h >= nums.size()) {
            // 够了
            results.push_back(cur);
            return ;
        }

        for (int i = h; i < nums.size(); i++) {
            swap(nums[i], nums[h]);
            cur.push_back(nums[h]);
            permuteCore(nums, h + 1);
            cur.pop_back();
            swap(nums[i], nums[h]);
        }
        return ;
    }
    vector<int> cur;
    vector<vector<int>> results;
};