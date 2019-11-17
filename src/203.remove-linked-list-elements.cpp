/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0), *curr = dummy;
        curr->next = head;
        while (curr->next) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

