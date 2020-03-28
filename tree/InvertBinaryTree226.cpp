#include "../define.h"
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        invertTreeCore(root);
        return root;
    }
    void invertTreeCore(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        swap(root->left, root->right);
        invertTreeCore(root->left);
        invertTreeCore(root->right);
    }
};