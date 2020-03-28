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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        if (root == NULL) {
            return results;
        }
        stack<TreeNode*> stack1;
        while(!stack1.empty() || root != NULL) {
            while(root != NULL) {
                results.push_back(root->val);
                stack1.push(root);
                root = root->left;
            }
            if (!stack1.empty()) {
                TreeNode* node = stack1.top();
                stack1.pop();
                if (node->right != NULL) {
                    root = node->right;
                }
            }
        }
        return results;
    }
};