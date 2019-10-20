class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode fake_head(0);
        fake_head.next = head;
        ListNode* node = &fake_head;
        while(node->next != NULL && node->next->next != NULL) {
            if (node->next->val == node->next->next->val) {
                // node->next = node->next->next->next;
                // 循环删除
                while(node->next->next != NULL && node->next->val == node->next->next->val) {
                    node->next = node->next->next;
                }
                node->next = node->next->next;
            } else {
                node = node->next;
            }
        }
        return fake_head.next;
    }
};