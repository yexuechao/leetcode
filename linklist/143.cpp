/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../define.h"
class Solution {
public:
    void reorderList(ListNode* head) {
        // 单双数先拆分开
        // 翻转两个链表
        // 两个链表连起来
        if (head == NULL || head->next == NULL) {
            return ;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* move_first = head;
        ListNode* move_second = head->next;
        SeparateList(move_first, move_second);

        ListNode* reverse_second = ReverseList(second);

        // merge
        ListNode ret_head(0);
        ListNode* node = &ret_head;
        second = reverse_second;
        while(first != NULL && second != NULL) {
            node->next = first;
            first = first->next;
            node = node->next;
            node->next = second;
            second = second->next;
            node = node->next;
        }

        if (first != NULL) {
            node->next = first;
        }
        if (second != NULL) {
            node->next = second;
        }

        head = ret_head.next;

        return ;
    }

    void SeparateList(ListNode* first, ListNode* second) {
        while(first != NULL && second != NULL) {
            first->next = second->next;
            first = first->next;
            if (first != NULL) {
                second->next = first->next;
                second = second->next;
            }
        }

        return ;
    }

    ListNode* ReverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

};