class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        ListNode tmp_head(0);
        ListNode* tmp_node = &tmp_head;
        tmp_node->next = head;

        while(tmp_node->next != NULL) {
            if (tmp_node->next->val == val) {
                tmp_node->next = tmp_node->next->next;
            } else {
                tmp_node = tmp_node->next;
            }
        }
        return tmp_head.next;
    }
};