class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        int head = 0;
        int tail = nums.size() - 1;
        while (head <= tail) {
            int mid = (head + tail) / 2;
            int mid_num = nums[mid];
            if (mid_num == target) {
                return true;
            }
            if (nums[head] == mid_num) {
                head++;
            } else if (nums[0] < mid_num) {
                // 递增过程 前半部分有序
                if (nums[0] <= target && target < mid_num) {
                    tail  = mid - 1;
                } else {
                    head = mid + 1;
                }
            } else {
                // nums[0] >= mid_num
                if (mid_num < target && target <= nums.back()) {
                    head = mid + 1;
                } else {
                    tail = mid - 1;
                }
            }
        }
        return false;
    }
};