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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        for (int i = 0; i < m - 1; ++i) {
            slow = slow->next;
        }
        ListNode* fast = slow->next;
        ListNode* pre;
        for (int i = 0; i < n - m; ++i) {
            ListNode* tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return dummy.next;
    }
};

