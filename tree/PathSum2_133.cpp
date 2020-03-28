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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return results;
        }
        // 回溯
        pathSumCore(root, sum, 0);

        return results;
    }

    void pathSumCore(TreeNode* root, int sum, int cur_sum) {
        if(root == NULL) {
            // 不应该来的路径
            return ;
        }
        if (root->left == NULL && root->right == NULL) {
            // 到达叶子节点
            if (cur_sum + root->val == sum) {
                cur.push_back(root->val);
                results.push_back(cur);
                cur.pop_back();
            }
            return ;
        }
        cur.push_back(root->val);
        pathSumCore(root->left, sum, cur_sum + root->val);
        pathSumCore(root->right, sum, cur_sum + root->val);
        cur.pop_back();
        return ;
    }

    vector<int> cur;
    vector<vector<int>> results;
};