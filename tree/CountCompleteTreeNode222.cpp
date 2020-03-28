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
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return countNodesCore(root);
    }
    int countNodesCore(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = TreeLevel(root->left);
        int right = TreeLevel(root->right);
        if (left == right) {
            return countNodesCore(root->right) + (1 << left);
        } else {
            return countNodesCore(root->left) + (1 << right);
        }
    }
    int TreeLevel(TreeNode* root) {
        int level = 0;
        while(root != NULL) {
            level++;
            root = root->left;
        }
        return level;
    }
};