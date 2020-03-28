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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == NULL) {
            return results;
        }
        queue<TreeNode*> queue1;
        queue1.push(root);
        int last_count = 1;
        int cur_count = 0;
        results.push_back(vector<int>());
        int v_idx = 0;
        while(!queue1.empty()) {
            TreeNode* node = queue1.front();
            queue1.pop();
            results[v_idx].push_back(node->val);
            last_count--;
            if (node->left != NULL) {
                cur_count++;
                queue1.push_back(node->left);
            }
            if (node->right != NULL) {
                cur_count++;
                queue1.push_back(node->right);
            }

            if (last_count <= 0 && cur_count > 0) {
                // 需要新的vector
                v_idx++;
                results.push_back(vector<int>());
                last_count = cur_count;
                cur_count = 0;
            }
        }
        return results;
    }
};