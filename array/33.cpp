#include "../define.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }
        int left = 0;
        int right = 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                // 找到了
                return mid;
            }
            if (nums[mid] >= nums.front()) {
                // 前面递增过程
                if (target > nums[mid]) {
                    left = mid + 1;
                } else if (target >= nums.front()) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // 后面的部分
                if (target < nums[mid]) {
                    right = mid - 1;
                } else if (target >= nums.front()) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};