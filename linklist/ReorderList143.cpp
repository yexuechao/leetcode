class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        // 先找到中点
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = cur->next;
        while(next != NULL && next->next != NULL) {
            pre = pre->next;
            cur = cur->next;
            next = next->next->next;
        }
        pre->next = NULL;
        // head -- pre
        // cur -- NULL 翻转链表
        ListNode* tail = reverseList(cur);
        // 穿插取值
        // ListNode* p = head;
        ListNode* node = new ListNode(0);
        ListNode* tmp = &node;
        ListNode* p = head;
        bool flag = true;
        while(p != NULL && tail != NULL) {
            if (flag) {
                node->next = p;
                p = p->next;
            } else {
                node->next = tail;
                tail = tail->next;
            }
            node = node->next;
            flag = !flag;
        }
        if (tail != NULL) {
            node->next = tail;
        }

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