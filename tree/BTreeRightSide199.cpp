/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightSideViewCore(root, result, 0);
        return result;
    }
    void rightSideViewCore(TreeNode* root, vector<int>& result, int level) {
        if (root == NULL) {
            return ;
        }
        if (result.size() == level) {
            result.push_back(root->val);
        }
        rightSideViewCore(root->right, result, level + 1);
        rightSideViewCore(root->left, result, level + 1);
        return ;
    }
};