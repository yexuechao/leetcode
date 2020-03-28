#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Node(int _val, Node* _left, Node* _right, Node* _next) {
//     val = _val;
//     left = _left;
//     right = _right;
//     next = _next;
// }