class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty() || citations.back() == 0) {
            return 0;
        }
        int left = 0;
        int right = citations.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if (citations[mid] < citations.size() - mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return citations.size() - left;
    }
};