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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root != NULL) {
            m_stack_.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = m_stack_.top();
        m_stack_.pop();
        TreeNode* root = node->right;
        while(root != NULL) {
            m_stack_.push(root);
            root = root->left;
        }

        return node->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (m_stack_.size() > 0);
    }
    stack<TreeNode*> m_stack_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */