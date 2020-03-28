#include "../define.h"
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }
        if (nums.back() > nums.front()) {
            // 没有旋转过
            return nums.front();
        }

        int head = 0;
        int tail = nums.size() - 1;
        while(head != tail) {
            int mid = (head + tail) / 2;
            if (nums[mid] == nums[head] && nums[head] == nums[tail]) {
                return FindMin(nums, head, tail);
            } else if (nums[mid] > nums.front()) {
                // 前半部分递增
                head = mid + 1;
            } else if (nums[mid] <= nums[tail]) {
                tail = mid;
            } else {
                head = mid + 1;
            }
        }

        return nums[head];
    }

    int FindMin(vector<int> a, int head, int tail) {
        int min = INT_MAX;
        for (int i = head; i <= tail; i++) {
            if (a[i] < min) {
                min = a[i];
            }
        }

        return min;
    }
};