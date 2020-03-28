#include "../define.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // if (nums.empty()) {
        //     return false;
        // }
        // int left = 0;
        // int right = nums.size() - 1;
        // while(left <= right) {
        //     int mid = (left + right) / 2;
        //     if (nums[mid] == target) {
        //         // 找到了
        //         return true;
        //     }
        //     if (nums[mid] == nums.front()) {
        //         left++;
        //         continue;
        //     }
        //     if (nums[mid] > nums.front()) {
        //         // 前面递增过程
        //         if (target > nums[mid]) {
        //             left = mid + 1;
        //         } else if (target >= nums.front()) {
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     } else {
        //         // 后面的部分
        //         if (target < nums[mid]) {
        //             right = mid - 1;
        //         } else if (target >= nums.front()) {
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     }
        // }
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }
            //前半部分有序
            if (nums[start] < nums[mid]) {
                //target在前半部分
                if (nums[mid] > target && nums[start] <= target) {
                    end = mid - 1;
                } else {  //否则，去后半部分找
                    start = mid + 1;
                }
            } else {
                //后半部分有序
                //target在后半部分
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid + 1;
                } else {  //否则，去后半部分找
                    end = mid - 1;

                }
            }
        }
        return false;
    }
};