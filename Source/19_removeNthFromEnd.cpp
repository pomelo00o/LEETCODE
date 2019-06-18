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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return nullptr;
        } 
        ListNode* curr = head;
        ListNode* prev = head;
        for (int i = 0; i < n; ++i) {
            curr = curr->next;
        }
        /*
            if n = len(list)
                remove the first element ---> head = head->next
        */
        if (!curr) {
            return head->next;
        }
        while (curr->next) {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};