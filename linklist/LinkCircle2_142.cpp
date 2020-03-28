#include "../define.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        ListNode* start = head;
        while(start != slow) {
            start = start->next;
            slow = slow->next;
        }
        return start;
    }
};