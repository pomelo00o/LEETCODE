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
        auto cnt = countListLength(head);
        if (cnt == 1) {
            return NULL;
        }
        if (cnt == n) {
            ListNode* curr = head;
            curr = NULL;
            return head->next;
        }
        if (cnt == 1) {
            ListNode* curr = head;
            while (curr != NULL) {
    		    curr = curr->next;
    	    }
            curr = NULL;
            return head;
        }
        auto index = cnt - n - 1;
        ListNode* curr = head;
        while (index--) {
        	curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        temp = NULL;
        return head;
    }

    int countListLength(ListNode* head) {
    	ListNode* curr = head;
    	int cnt = 0;
    	while (curr != NULL) {
    		curr = curr->next;
    		cnt++;
    	}
    	return cnt;
    }
};