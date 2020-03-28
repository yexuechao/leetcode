class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) {
            return results;
        }
        permuteUniqueCore(nums, 0);
        results.assign(unique_res.begin(), unique_res.end());
        return results;
    }
    void permuteUniqueCore(vector<int>& nums, int h) {
        if (h >= nums.size()) {
            // 够了
            unique_res.insert(cur);
            return ;
        }

        for (int i = h; i < nums.size(); i++) {
            swap(nums[i], nums[h]);
            cur.push_back(nums[h]);
            permuteUniqueCore(nums, h + 1);
            cur.pop_back();
            swap(nums[i], nums[h]);
        }
        return ;
    }
    vector<int> cur;
    vector<vector<int>> results;
    set<vector<int>> unique_res;
};