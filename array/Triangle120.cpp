#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }
        vector<int> result(triangle.back().size());
        result[0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); i++) {
            for(int j = i; j >= 0; j--) {
                // 3
                int first = j - 1;
                int first_val = (first >= 0 && first < i) ? (triangle[i][j] + result[first]) : INT_MAX;
                int second = j;
                int second_val = (second >= 0 && second < i) ? (triangle[i][j] + result[second]) : INT_MAX;
                result[j] = min(first_val, second_val);
            }
        }
        int min_num = INT_MAX;
        for (size_t i = 0; i < result.size(); i++) {
            min_num = min(result[i], min_num);
        }
        return min_num;
    }
};