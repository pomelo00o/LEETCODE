/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 1 2 3 4 5
        // s f t x y
        // basic idea is to loop n - m times
        // within each iteration: put t between s and f
        // f.next = f.next.next
        // s.next = t
        // t.next = s.next
        ListNode *dummy = new ListNode(-1), *slow = dummy;
        dummy->next = head;
        for (int i = 1; i < m; ++i) {
            slow = slow->next;
        }
        ListNode* fast = slow->next;
        for (int j = m; j < n; ++j) {
            ListNode* tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return dummy->next;
    }
};

