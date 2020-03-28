class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k || k <= 0) {
            return vector<int>();
        }
        vector<int> max;
        deque<int> index;
        for (int i = 0; i < k; i++) {
            while(!index.empty() && nums[i] > nums[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
        }

        for (int i = k; i < nums.size(); i++) {
            max.push_back(nums[index.front()]);
            while(!index.empty() && nums[i] > nums[index.back()]) {
                index.pop_back();
            }
            if (!index.empty() && index.front() <= i - k) {
                index.pop_front();
            }
            index.push_back(i);
        }
        // 最后还有一个
        max.push_back(nums[index.front()]);

        return max;
    }
};