class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL || m <= 0 || n <= 0 || m > n) {
            return NULL;
        }
        if (m == n) {
            return head;
        }
        ListNode* ml = head;
        ListNode* nl = head;
        ListNode ahead_m(0);
        ahead_m.next = head;
        ListNode* pre = &ahead_m;
        while(m > 1) {
            ml = ml->next;
            nl = nl->next;
            pre = pre->next;
            m--;
            n--;
        }
        while(n > 1) {
            nl = nl->next;
            n--;
        }
        // ListNode* mll = ml;
        // ListNode* nll = nl;
        ListNode* cur = ml;
        ListNode* pre_mark = pre;
        ListNode* next_mark = nl->next;
        while(cur != next_mark) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        pre_mark->next = nl;
        ml->next = cur;
        return ahead_m.next;
    }

};