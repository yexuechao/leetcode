#include <queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return 0;
        }
        // 快排or堆
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (size_t i = 0; i < nums.size(); i++) {
            if (min_heap.size() < k) {
                min_heap.push(nums[i]);
                continue;
            } else {
                if (nums[i] > min_heap.top()) {
                    min_heap.pop();
                    min_heap.push(nums[i]);
                }
            }
        }

        return min_heap.top();
    }

    int findKthLargest2(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return 0;
        }
        // 快排
        num_k = k;
        return QuickSort(nums, 0, nums.size() - 1);
    }

    int QuickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nums[left];
        }
        int idx = QuickSortCore(nums, left, right);
        if (idx == nums.size() - num_k) {
            return nums[idx];
        }

        if (idx > nums.size() - num_k) {
            return QuickSort(nums, left, idx - 1);
        }

        return QuickSort(nums, idx + 1, right);
    }

    int QuickSortCore(vector<int>& nums, int left, int right) {
        // 选择眼睛
        int eye = nums[left];
        while(left < right) {
            while(left < right && nums[right] >= eye) {
                right--;
            }
            if (left < right) {
                nums[left] = nums[right];
                left++;
            }

            while(left < right && nums[left] < eye) {
                left++;
            }
            if (left < right) {
                nums[right] = nums[left];
                right--;
            }
        }
        nums[left] = eye;
        return left;
    }
    int num_k;
};