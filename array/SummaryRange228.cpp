#include <vector>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) {
            return vector<string>();
        }
        int cur = 0;
        vector<string> results;
        while(cur < nums.size() - 1) {
            if (nums[cur] + 1 != nums[cur + 1]) {
                results.push_back(to_string(nums[cur]));
            } else {
                int idx = cur + 2;
                while(idx < nums.size() && nums[idx] == nums[idx - 1] + 1) {
                    idx++;
                }
                idx--;
                string start = to_string(nums[cur]);
                string end = to_string(nums[idx]);
                results.push_back(start + "->" + end);
                cur = idx;
            }
            cur++;
        }
        if (cur == nums.size() - 1) {
            results.push_back(to_string(nums[cur]));
        }
        return results;
    }
};