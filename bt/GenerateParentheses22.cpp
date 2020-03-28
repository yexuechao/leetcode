class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return vector<string>();
        }
        generateParenthesisCore(n, 0, 0, 0);
        return results;
    }
    void generateParenthesisCore(int n, int h, int left, int right) {
        if (h >= 2 * n) {
            results.push_back(cur);
            return ;
        }
        // 两个都取
        if (left < n) {
            cur.push_back('(');
            generateParenthesisCore(n, h + 1, left + 1, right);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            generateParenthesisCore(n, h + 1, left, right + 1);
            cur.pop_back();
        }
    }
    string cur;
    vector<string> results;
};