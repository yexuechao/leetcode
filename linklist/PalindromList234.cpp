class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        // 先翻转链表，在比较是否相同
        // 翻转链接翻一半
        // 先找到中间
        ListNode* mid = head;
        ListNode* last = head;
        while (last != NULL && last->next != NULL) {
            mid = mid->next;
            last = last->next->next;
        }

        ListNode* pre = reverseList(head, mid);
        if (last != NULL) {
            mid = mid->next;
        }
        while (mid != NULL && pre != NULL) {
            if (mid->val != pre->val) {
                return false;
            }
            mid = mid->next;
            pre = pre->next;
        }
        if (mid == NULL && pre == NULL) {
            return true;
        }
        return false;
    }

    ListNode* reverseList(ListNode* head, ListNode* tail) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};