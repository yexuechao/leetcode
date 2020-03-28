/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../define.h"
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // 有效二叉树
        vector<int> val;
        isValidBSTCore(root, val);
        for (size_t i = 1; i < val.size(); i++) {
            // 看下是否有序
            if (val[i - 1] >= val[i]) {
                return false;
            }
        }
        return true;
    }
    void isValidBSTCore(TreeNode* root, vector<int>& val) {
        if (root == NULL) {
            return ;
        }
        isValidBSTCore(root->left, val);
        val.push_back(root->val);
        isValidBSTCore(root->right, val);
        return ;
    }
};