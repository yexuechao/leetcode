#include "../define.h"
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.size() < k) {
            return vector<int>();
        }
        QuickSort(input, k, 0, input.size() - 1);
        vector<int> result(input.begin(), input.begin() + k);
        return result;
    }

    void QuickSort(vector<int>& input, int k, int left, int right) {
        if (left >= right) {
            return ;
        }
        int idx = QuickSortCore(input, left, right);
        if (idx == k - 1) {
            return ;
        } else if (idx < k - 1) {
            QuickSort(input, k, idx + 1, right);
        } else {
            QuickSort(input, k, left, idx - 1);
        }

        return ;
    }

    int QuickSortCore(vector<int>& input, int left, int right) {
        int eye = input[left];
        while(left < right) {
            while(left < right && input[right] >= eye) {
                right--;
            }
            input[left] = input[right];
            while(left < right && input[left] <= eye) {
                left++;
            }
            input[right] = input[left];
        }
        input[left] = eye;
        return left;
    }
};