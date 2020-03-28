/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
#include "../define.h"
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        connectCore(root);
        return root;
    }
    void connectCore(Node* root) {
        if (root == NULL) {
            return ;
        }
        if (root->left != NULL) {
            root->left->next = root->right;
        }
        if (root->right != NULL && root->next != NULL) {
            root->right->next = root->next->left;
        }
        connectCore(root->left);
        connectCore(root->right);
        return ;
    }
};