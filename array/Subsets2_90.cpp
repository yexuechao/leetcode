#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) {
            vector<vector<int>> res;
            res.push_back(vector<int>());
            return res;
        }
        subsetsWithDupCore(nums, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }

    void subsetsWithDupCore(vector<int>& nums, int h) {
        if (h >= nums.size()) {
            // cur 排序
            vector<int> cur_tmp = cur;
            sort(cur_tmp.begin(), cur_tmp.end());
            result.insert(cur_tmp);
            return ;
        }
        // 不取
        subsetsWithDupCore(nums, h + 1);

        // 取
        cur.push_back(nums[h]);
        subsetsWithDupCore(nums, h + 1);
        cur.pop_back();
        return ;
    }
    vector<int> cur;
    set<vector<int>> result;
};