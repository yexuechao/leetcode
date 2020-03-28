class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) {
            return results;
        }
        combineCore(n, k, 1);
        return results;
    }

    void combineCore(int n , int k, int h) {
        if (h > n) {
            if (cur.size() == k) {
                results.push_back(cur);
            }
            return ;
        }

        // 取或者不取
        // 不取，有个剪枝逻辑
        if (k - cur.size() <= n - h) {
            combineCore(n, k, h + 1);
        }

        // 取，也有个剪枝逻辑
        if (cur.size() < k) {
            cur.push_back(h);
            combineCore(n, k, h + 1);
            cur.pop_back();
        }
        return ;
    }

    vector<int> cur;
    vector<vector<int>> results;
};