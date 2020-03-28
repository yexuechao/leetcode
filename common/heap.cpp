#include "../define.h"
class Solution{
    public:
    void MaxHeapSort(vector<int>& arr) {
        // 建堆
        for (int i = arr.size() / 2 - 1; i >= 0; i--) {
            HeadSortCore(arr, i, arr.size() - 1);
        }

        // 开始建堆
        for (int i = arr.size() - 1; i >= 1; i--) {
            swap(arr[0], arr[i]);
            HeadSortCore(arr, 0, i - 1);
        }

        return ;
    }

    void HeadSortCore(vector<int>& arr, int cur, int size) {
        while(2 * cur + 1 <= size) {
            // 取下面的节点
            int idx = cur * 2 + 1;
            if (idx + 1 <= size && arr[idx] < arr[idx + 1]) {
                idx = idx + 1;
            }
            if (arr[cur] < arr[idx]) {
                swap(arr[cur], arr[idx]);
                cur = idx;
            } else {
                break;
            }
        }
        return ;
}
};