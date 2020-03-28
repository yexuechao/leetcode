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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return vector<TreeNode*>();
        }
        return generateTreesCore(1, n);
    }
    vector<TreeNode*> generateTreesCore(int left, int right) {
        vector<TreeNode*> results;
        if (left > right) {
            results.push_back(NULL);
        }
        for (int i = left; i <= right; i++) {
            // 以i为根节点，深度遍历所有的情况
            vector<TreeNode*> left_res = generateTreesCore(left, i - 1);
            vector<TreeNode*> right_res = generateTreesCore(i + 1, right);
            for (int j = 0; j < left_res.size(); j++) {
                for (int k = 0; k < right_res.size(); k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = left_res[j];
                    node->right = right_res[k];
                    results.push_back(node);
                }
            }
        }
        return results;
    }
};