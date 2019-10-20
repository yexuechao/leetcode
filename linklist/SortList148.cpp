class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 单链表快排
        // if (head == NULL) {
        //     return NULL;
        // }
        // QuickSortListCore(head, NULL);
        MergeSort(head, NULL);
        return head;
    }

    void QuickSortListCore(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return ;
        }
        // 拿个眼睛来
        int target = head->val;
        ListNode* first = head;
        ListNode* second = head->next;
        while(second != tail) {
            if (second->val < target) {
                first = first->next;
                swap(first->val, second->val);
            }
            second = second->next;
        }
        swap(first->val, head->val);
        QuickSortListCore(head, first);
        QuickSortListCore(first->next, tail);
        return ;
    }

    void MergeSort(ListNode* head, ListNode* tail) {
        if (head == NULL || head == tail) {
            return ;
        }
        // 找到中点
        // ListNode* mid = NULL;
        // if (head->next == NULL) {
        //     mid = head;
        // }
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* next = head;
        while(next != tail && next->next != tail) {
            pre = pre->next;
            cur = cur->next;
            next = next->next->next;
        }
        pre->next = NULL;
        // 先排好
        MergeSort(head);
        MergeSort(cur);
        // 再合并
        MergeSortCore(head, mid->next, mid->next, tail);
    }
    ListNode* MergeSortCore(ListNode* p1, ListNode* p1_tail, ListNode* p2, ListNode* p2_tail) {
        // if (p1 == p1_tail) {
        //     return p2;
        // }
        // if (p2 == p2_tail) {
        //     return p1;
        // }
        ListNode node(0);
        ListNode* f_head = &node;
        while(p1 != p1_tail && p2 != p2_tail) {
            if (p1->val <= p2->val) {
                f_head->next = p1;
                p1 = p1->next;
            } else {
                f_head->next = p2;
                p2 = p2->next;
            }
            f_head = f_head->next;
        }
        if (p1 != p1_tail) {
            f_head->next = p1;
        } else {
            f_head->next = p2;
        }
        return node.next;
    }

};