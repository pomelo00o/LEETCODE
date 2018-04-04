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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto p = l1;
        auto q = l2;
        ListNode *Ans = new ListNode(0);
        auto *Curr = Ans;
        auto sum = 0;
        auto carry = 0;
        while (true) {
        	if (p) {
        		sum += p->val;
        		p = p->next;
        	}
        	if (q) {
        		sum += q->val;
        		q = q->next;
        	}
        	Curr->val = sum % 10;
        	sum /= 10;
        	if (p || q || sum) {
        		Curr->next = new ListNode(0);
        		Curr = Curr->next;
        	} else {
                break;
            }
        }
        return Ans;
    }
};