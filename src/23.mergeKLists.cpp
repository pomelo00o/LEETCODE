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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return nullptr;
		}
		int n = lists.size();
		/*
			Divide and conquer
			[
				[A],
				[B],
				[C],
				[D],
				[E]
			]
			A--D	B--E	C
		*/
		while (n > 1) {
			int k = (n + 1) / 2;
			for (int i = 0; i < n / 2; ++i) {
				lists[i] = mergeTwoLists(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* dummy = new ListNode(-1);
		ListNode* curr = dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				curr->next = l1;
				l1 = l1->next;
			} else {
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		curr->next = l1 ? l1 : l2;
		return dummy->next;
	}
};