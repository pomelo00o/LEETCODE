/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        ListNode* curr = pre;
        dummy->next = head;
        int list_len = 0;
        while (curr = curr->next) {
            ++list_len;
        }
        while (list_len >= k) {
            curr = pre->next;
            int i = 1;
            while (i < k) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
                ++i;
            }
            pre = curr;
            list_len -= k;
        }
        return dummy->next;
    }
};