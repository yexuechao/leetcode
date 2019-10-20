class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while(slow != fast);
        int head = nums[0];
        while(head != slow) {
            slow = nums[slow];
            head = nums[head];
        }

        return head;
    }
};