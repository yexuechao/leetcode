#include <stack>
using namespace std;
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        stack<ListNode*> stask1;
        stask1.push(head);
        ListNode* node = head;
        node = node->next;
        while(node != NULL) {
            // 比较数值
            ListNode* top = stask1.top();
            if (top->val <= node->val) {
                stask1.push(node);
                node = node->next;
                continue;
            }
            // 就要排序
            int val = node->val;
            ListNode* tmp_restore = NULL;
            while(!stask1.empty()) {
                ListNode* tmp = stask1.top();
                if (tmp->val <= val) {
                    tmp_restore = tmp->next;
                    tmp->next->val = val;
                    break;
                } else {
                    stask1.pop();
                    // 交换位置
                    tmp->next->val = tmp->val;
                    if (stask1.empty()) {
                        tmp->val = val;
                        tmp_restore = tmp;
                    }
                }
            }
            // 帮所有节点全部push回去
            while(tmp_restore != node->next) {
                stask1.push(tmp_restore);
                tmp_restore = tmp_restore->next;
            }
            node = node->next;
        }
        return head;
    }

};