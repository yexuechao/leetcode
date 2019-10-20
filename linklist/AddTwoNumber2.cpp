class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode fake_head(0);
        ListNode* cur = &fake_head;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int l1_val = 0;
            if (l1 != NULL) {
                l1_val = l1->val;
            }
            int l2_val = 0;
            if (l2 != NULL) {
                l2_val = l2->val;
            }
            int sum = l1_val + l2_val + carry;
            carry = sum / 10;
            int val = sum % 10;
            ListNode* node = new ListNode(val);
            cur->next = node;
            cur = cur->next;
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            ListNode* node = new ListNode(1);
            cur->next = node;
        }
        return fake_head.next;
    }
};