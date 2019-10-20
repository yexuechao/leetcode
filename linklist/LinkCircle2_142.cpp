class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* first = head->next;
        ListNode* second = head->next;
        if (second == NULL) {
            return NULL;
        }
        second = second->next;
        while(first != second) {
            if (second == NULL) {
                return NULL;
            }
            first = first->next;
            second = second->next;
            if (second == NULL) {
                return NULL;
            }
            second = second->next;
        }
        ListNode* node = head;
        while(node != first) {
            node = node->next;
            first = first->next;
        }
        return node;
    }
};