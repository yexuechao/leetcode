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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        sumNumbersCore(root);
        return accumulate(nums.begin(), nums.end(), 0);

    }
    void sumNumbersCore(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        if (root->left == NULL && root->right == NULL) {
            // 根节点
            cur *= 10;
            cur += root->val;
            nums.push_back(cur);
            cur /= 10;
            return ;
        }
        cur *= 10;
        cur += root->val;
        sumNumbersCore(root->left);
        sumNumbersCore(root->right);
        cur /= 10;
        return ;
    }

    int cur;
    vector<int> nums;
};