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
    vector<int> inorderTraversal(TreeNode* root) {
        // 栈
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        stack<TreeNode*> stack1;
        while(!stack1.empty() || root != NULL) {
            while(root != NULL) {
                stack1.push(root);
                root = root->left;
            }
            if (!stack1.empty()) {
                TreeNode* node = stack1.top();
                stack1.pop();
                result.push_back(node->val);
                if (node->right != NULL) {
                    root = node->right;
                }
            }
        }

        return result;
    }
};