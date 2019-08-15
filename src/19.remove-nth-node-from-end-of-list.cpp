/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** slow = &head;
        ListNode* fast = head;
        for (int i = 1; i < n; ++i) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = &((*slow)->next);
            fast = fast->next;
        }
        *slow = (*slow)->next;
        return head;
    }
};

