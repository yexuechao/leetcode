#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return vector<vector<int>>();
        }
        // 我想先排序：按照第一个的大小排序
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int idx = 0;
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& first = result[idx];
            vector<int> second = intervals[i];
            // 合并
            if (second[0] > first[1]) {
                result.push_back(second);
                idx++;
            } else {
                if (first[1] < second[1]) {
                    first[1] = second[1];
                }
            }
        }
        return result;
    }
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        // 外部确保size = 2
        return a[0] < b[0];
    }
};