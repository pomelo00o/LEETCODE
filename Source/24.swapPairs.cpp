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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        /*
            see https://www.jianshu.com/p/bd4dc088e97a for more info
        */
        while (prev->next && prev->next->next) {
            ListNode* temp = prev->next->next;
            prev->next->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            prev = temp->next;
        }
        return dummy->next;
    }
};