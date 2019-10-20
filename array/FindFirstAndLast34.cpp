class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return vector<int>(2, -1);
        }
        // 二分之中再二分
        int idx = BinarySearch(nums, 0, nums.size() - 1, target);
        if (idx == -1) {
            return vector<int>(2, -1);
        }
        int real_head = idx;
        int real_tail = idx;
        while (real_head > 0 && nums[real_head - 1] == target) {
            real_head = BinarySearch(nums, 0, real_head - 1, target);
        }
        while(real_tail < nums.size() - 1 && nums[real_tail + 1] == target) {
            real_tail = BinarySearch(nums, real_tail + 1, nums.size() - 1, target);
        }
        vector<int> result{real_head, real_tail};
        return result;
    }
    int BinarySearch(const vector<int>& nums, int head, int tail, int target) {
        while(head <= tail) {
            int mid = (head + tail) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                tail = mid - 1;
            } else {
                head = mid + 1;
            }
        }
        return -1;
    }
};