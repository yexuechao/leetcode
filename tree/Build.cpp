/**
 * Definition for binary tree
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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() != vin.size()) {
            return NULL;
        }
        return reConstructBinaryTreeCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
    TreeNode* reConstructBinaryTreeCore(vector<int> pre, int pre_start, int pre_end, vector<int> vin, int vin_start, int vin_end) {
        if (pre_start > pre_end) {
            return NULL;
        }
        // 取出根
        TreeNode* root = new TreeNode(pre[pre_start]);
        // 中序遍历找到该节点
        int idx = vin_start;
        while(root->val != vin[idx]) {
            idx++;
        }
        // 找到了，计算左右节点数量
        int left_num = idx - vin_start;
        int right_num = vin_end - idx;
        root->left = reConstructBinaryTreeCore(pre, pre_start, pre_start + left_num - 1, vin, vin_start, idx - 1);
        root->right = reConstructBinaryTreeCore(pre, pre_start + left_num, pre_end, vin, idx + 1, vin_end);
        return root;
    }
};