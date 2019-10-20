class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= 0 || n < 1) {
            return result;
        }
        cur_sum = 0;
        CombinationSum3Core(k, n, 1);
        return result;
    }
    void CombinationSum3Core(int k, int n, int h) {
        if (k <= 0) {
            // cur_sum = accumulate(cur.begin(), cur.end(), 0);
            if (cur_sum == n) {
                result.push_back(cur);
            }
            return ;
        }
        if (cur_sum > n || h > 9) {
            return ;
        }

        CombinationSum3Core(k, n, h + 1);
        cur_sum += h;
        cur.push_back(h);
        CombinationSum3Core(k - 1, n, h + 1);
        cur_sum -= h;
        cur.pop_back();
        return ;
    }
    vector<int> cur;
    int cur_sum;
    vector<vector<int>> result;
};