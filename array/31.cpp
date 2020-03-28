class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return ;
        }

        // 从后向前遍历 找一个后 > 前的
        int i = nums.size() - 2;
        int j = nums.size() - 1;
        while (i >= 0) {
            if (nums[j] > nums[i]) {
                break;
            }
            i--;
            j--;
        }

        if (i < 0) {
            // 全逆序
            reverse(nums.begin(), nums.end());
            return ;
        }

        // nums.size(）-1 --> j 找第一个 > i的
        int k = nums.size() - 1;
        while(nums[k] <= nums[i]) {
            k--;
        }

        // nums[k] >= nums[i], swap
        swap(nums[k], nums[i]);

        // j 到 nums.size() - 1 逆序排列
        int left = j;
        int right = nums.size() - 1;
        while (left < right) {
            swap(nums[left], nums[right]);
        }

        return ;
    }
};