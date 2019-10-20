class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k <= 0 || head == NULL) {
            return head;
        }
        // 先算出len
        ListNode* h1 = head;
        int len = 0;
        while(h1 != NULL) {
            len++;
            h1 = h1->next;
        }
        int rotate = k % len;
        // 指针移到对应位置,
        int step = len - rotate;
        ListNode* head2 = head;
        while(step > 1) {
            head2 = head2->next;
            step--;
        }
        // 先把链接拆开
        ListNode* node = head2;
        head2 = head2->next;
        node->next = NULL;
        // 翻转链接
        ListNode* first = reverseList(head);
        ListNode* second = reverseList(head2);
        head->next = second;
        ListNode* res = reverseList(first);
        return res;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

};