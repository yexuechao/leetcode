class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        // length
        int len_a = 0;
        ListNode* tmp_a = headA;
        while(tmp_a != NULL) {
            len_a++;
            tmp_a = tmp_a->next;
        }
        int len_b = 0;
        ListNode* tmp_b = headB;
        while(tmp_b != NULL) {
            len_b++;
            tmp_b = tmp_b->next;
        }
        int distance = abs(len_a - len_b);
        if (len_a >= len_b) {
            while (headA != NULL && distance > 0) {
                headA = headA->next;
                distance--;
            }
        } else {
            while (headB != NULL && distance > 0) {
                headB = headB->next;
                distance--;
            }
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        ListNode* node = headA;
        return node;
    }
};