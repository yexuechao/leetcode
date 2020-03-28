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
        if (root->left == NULL && root->right == NULL) {
            return ;
        }
        if (root->left != NULL && root->right != NULL) {
            root->left->next = root->right;
        }
        Node* node = root->right ? root->right : root->left;
        Node* head = root->next;
        while(head != NULL && head->left == NULL && head->right == NULL) {
            head = head->next;
        }

        if (head != NULL) {
            if (head->left != NULL) {
                node->next = head->left;
            } else {
                node->next = head->right;
            }
        }
        connectCore(root->right);
        connectCore(root->left);
        return ;
    }
};