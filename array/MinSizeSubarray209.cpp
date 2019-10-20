#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int result = nums.size() + 1;
        int left = 0;
        int right = -1;
        int sum = 0;
        while(left < nums.size() - 1) {
            if (sum < s) {
                if (right >= (int)nums.size() - 1) {
                    break;
                }
                right++;
                sum += nums[right];
            } else {
                sum -= nums[left];
                left++;
            }
            if (sum >= s) {
                result = min(result, right - left + 1);
            }
        }
        return (result != nums.size() - 1) ? result : 0;
    }

    // 暴力法超时
    // int result = INT_MAX;
    // for (int left = 0; left < nums.size(); left++) {
    //     // 起始位置 left
    //     for (int right = left; right < nums.size(); right++) {
    //         vector<int>::iterator itr_left = nums.begin() + left;
    //         vector<int>::iterator itr_right = nums.begin() + right + 1;
    //         int sum = accumulate(itr_left, itr_right, 0);
    //         if (sum >= s) {
    //             result = min(result, right - left + 1);
    //             break;
    //         }
    //     }
    // }
    // return (result != INT_MAX) ? result : 0;

};