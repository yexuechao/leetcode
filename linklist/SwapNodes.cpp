class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        return swapPairsCore(head, head->next);
    }
    ListNode* swapPairsCore(ListNode* n1, ListNode* n2) {
        if (n1 == NULL) {
            return NULL;
        }
        if (n2 == NULL) {
            return n1;
        }
        // 去两个next
        ListNode* n3 = NULL;
        if (n2->next != NULL) {
            n3 = n2->next->next;
        }
        ListNode* node = swapPairsCore(n2->next, n3);
        n2->next = n1;
        n1->next = node;
        return n2;
    }
};