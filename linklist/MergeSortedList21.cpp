namespace MergeSortedList21 {

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* node = NULL;
        if (l1->val >= l2->val) {
            node = l2;
            l2 = l2->next;
        } else {
            node = l1;
            l1 = l1->next;
        }
        ListNode* head = node;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val >= l2->val) {
                node->next = l2;
                l2 = l2->next;
                node = node->next;
            } else {
                node->next = l1;
                l1 = l1->next;
                node = node->next;
            }
        }
        if (l1 != NULL) {
            node->next = l1;
        } else {
            node->next = l2;
        }
        return head;
    }
};

}; // namespace MergeSortedList21