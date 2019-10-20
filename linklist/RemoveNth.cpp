class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0 || head == NULL) {
            return NULL;
        }
        // 移动head
        ListNode* h1 = head;
        int k = n;
        while (h1 != NULL && k > 0) {
            h1 = h1->next;
            k--;
        }
        if (k > 0) {
            // 非法
            return NULL;
        }

        ListNode fake_head(0);
        fake_head.next = head;
        ListNode* pre = &fake_head;
        ListNode* node = head;
        while(h1 != NULL) {
            h1 = h1->next;
            node = node->next;
            pre = pre->next;
        }
        pre->next = node->next;
        return fake_head.next;
    }
};