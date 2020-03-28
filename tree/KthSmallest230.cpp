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
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL || k <= 0) {
            return 0;
        }
        result = root->val;
        kthSmallestCore(root, k);
        return result;
    }

    void kthSmallestCore(TreeNode* root, int& k) {
        // 中序遍历
        if (root == NULL) {
            return ;
        }
        kthSmallestCore(root->left, k);
        if (k == 1) {
            result = root->val;
            return ;
        }
        k--;
        kthSmallestCore(root->right, k);
    }
    int result;
};