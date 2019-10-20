class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left != right) {
            mid = (left + right) / 2;
            if (mid >= nums.size() - 1) {
                return mid;
            }
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};