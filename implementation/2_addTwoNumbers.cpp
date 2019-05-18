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
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		auto carry = 0;
		while (l1 || l2) {
			auto v1 = l1 ? l1->val : 0;
			auto v2 = l2 ? l2->val : 0;
			auto sum = v1 + v2 + carry;
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
		}
		if (carry) {
			cur->next = new ListNode(1);
		}
		return dummy->next;
    }
};