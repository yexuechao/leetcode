#include<vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }
        int result = 0;
        // 先排序
        sort(citations.begin(), citations.end());
        int count = 1;
        for (int i = citations.size() - 1; i >= 0; i--) {
            if (count == citations[i]) {
                // count篇论文引用citation[i]次
                result = count;
                break;
            } else if (citations[i] > count) {
                result = count;
                count++;
            } else {
                break;
            }
        }
        return result;
    }
};