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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        pre = NULL;
        flattenCore(root);
        return ;
    }

    void flattenCore(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        flattenCore(root->right);
        flattenCore(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
    TreeNode* pre;
};