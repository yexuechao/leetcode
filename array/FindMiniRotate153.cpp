#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums[0] <= nums.back()) {
            return nums[0];
        }
        int head = 0;
        int tail = nums.size() - 1;
        while(head <= tail) {
            if (head + 1 == tail) {
                return nums[tail];
            }
            int mid = (head + tail) / 2;
            int mid_num = nums[mid];
            if (nums[head] < mid_num) {
                head = mid;
            } else {
                tail = mid;
            }
        }
        return 0;
    }
};