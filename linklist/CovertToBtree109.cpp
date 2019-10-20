class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* right = head;
        while(right->next != NULL) {
            right = right->next;
        }
        // 找到最后一个节点
        return sortedListToBSTCore(head, right);
    }
    TreeNode* sortedListToBSTCore(ListNode* left, ListNode* right) {
        if (left == right) {
            TreeNode* node = new TreeNode(left->val);
            return node;
        }
        //先找到中间节点
        ListNode* tmp_left = left;
        int len = 0;
        while(tmp_left != right->next) {
            len++;
            tmp_left = tmp_left->next;
        }
        ListNode* mid = left;
        ListNode fake_head(0);
        fake_head.next = mid;
        ListNode* fake_node = &fake_head;
        if (len % 2 == 0) {
            len = len / 2;
        } else {
            len = len / 2 + 1;
        }
        while(len > 1) {
            mid = mid->next;
            fake_node = fake_node->next;
            len--;
        }
        TreeNode* tn_left = NULL;
        if (fake_node == &fake_head) {
        } else {
            tn_left = sortedListToBSTCore(left, fake_node);
        }

        TreeNode* tn_right = sortedListToBSTCore(mid->next, right);
        TreeNode* node = new TreeNode(mid->val);
        node->left = tn_left;
        node->right = tn_right;
        return node;
    }
};