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
    int maxProduct(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        min_distance = INT_MAX;
        FillSum(root);
        root_node = root;

        CalcMax(root);
        int64_t num1 = node_sum[max_node];
        int64_t num2 = node_sum[root] - node_sum[max_node];

        return (num1 * num2 % (1000000007));

    }

    void CalcMax(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        // 记录相差最小的node
        // 以左节点为根
        if (root->left != NULL) {
            if (abs(node_sum[root_node] - 2 * node_sum[root->left]) < min_distance) {
                min_distance = abs(node_sum[root_node] - 2 * node_sum[root->left]);
                max_node = root->left;
            }
        }

        if (root->right != NULL) {
            if (abs(node_sum[root_node] - 2 * node_sum[root->right]) < min_distance) {
                min_distance = abs(node_sum[root_node] - 2 * node_sum[root->right]);
                max_node = root->right;
            }
        }
        if (root->left != NULL) {
            CalcMax(root->left);
        }
        if (root->right != NULL) {
            CalcMax(root->right);
        }

        return ;
    }

    void FillSum(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        if (root->left != NULL) {
            FillSum(root->left);
        }
        if (root->right != NULL) {
            FillSum(root->right);
        }
        // 当前节点为根节点时，整棵树的和
        int64_t sum = root->val;
        if (root->left != NULL) {
            // sum += root->left->val;
            sum += node_sum[root->left];

        }
        if (root->right != NULL) {
            // sum += root->right->val;
            sum += node_sum[root->right];
        }
        node_sum[root] = sum;
    }

    unordered_map<TreeNode*, int64_t> node_sum;

    int32_t min_distance;
    TreeNode* max_node;
    TreeNode* root_node;
};