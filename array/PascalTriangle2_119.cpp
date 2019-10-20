class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return vector<int>();
        }
        vector<int> result(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                result[j] = result[j] + result[j - 1];
            }
        }
        return result;
    }
};