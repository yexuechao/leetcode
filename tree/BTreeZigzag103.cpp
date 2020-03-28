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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == NULL) {
            return results;
        }
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        stack1.push(root);
        int time = 0;
        while(!stack1.empty() || !stack2.empty()) {
            vector<int> res;
            if (time % 2 == 0) {
                while(!stack1.empty()) {
                    TreeNode* node = stack1.top();
                    res.push_back(node->val);
                    stack1.pop();
                    if (node->left != NULL) {
                        stack2.push(node->left);
                    }
                    if (node->right != NULL) {
                        stack2.push(node->right);
                    }
                }
            } else {
                while(!stack2.empty()) {
                    TreeNode* node = stack2.top();
                    res.push_back(node->val);
                    stack2.pop();
                    if (node->right != NULL) {
                        stack1.push(node->right);
                    }
                    if (node->left != NULL) {
                        stack1.push(node->left);
                    }
                }
            }
            time++;
            results.push_back(res);
        }
        return results;
    }
};