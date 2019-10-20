class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) {
            return NULL;
        }
        ListNode less_code(0);
        ListNode greater_node(0);
        ListNode* less_code_h = &less_code;
        ListNode* greater_node_h = &greater_node;
        while(head != NULL) {
            if (head->val < x) {
                less_code_h->next = head;
                less_code_h = less_code_h->next;
            } else {
                greater_node_h->next = head;
                greater_node_h = greater_node_h->next;
            }
            head = head->next;
        }
        greater_node_h->next = NULL;
        less_code_h->next = greater_node.next;
        return less_code.next;
    }
};