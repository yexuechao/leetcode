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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 用回溯法找到节点，把联调串起来
        vector<TreeNode*> p_nodes;
        FindNode(root, p, p_nodes);

        vector<TreeNode*> q_nodes;
        FindNode(root, q, q_nodes);

        int p_size = p_nodes.size() - 1;
        int q_size = q_nodes.size() - 1;
        int min_size = min(p_size, q_size);
        while(min_size >= 0) {
            if (p_nodes[min_size] == q_nodes[min_size]) {
                return p_nodes[min_size];
            }
            min_size--;
        }
        return NULL;
    }

    bool FindNode(TreeNode* root, TreeNode* find, vector<TreeNode*>& nodes) {
        if (root == NULL) {
            return false;
        }
        if (root == find) {
            // 找到了
            nodes.push_back(root);
            return true;
        }
        // 取左边
        nodes.push_back(root);
        if (FindNode(root->left, find, nodes)) {
            return true;
        }
        if (FindNode(root->right, find, nodes)) {
            return true;
        }
        nodes.pop_back();
        return false;
    }

};