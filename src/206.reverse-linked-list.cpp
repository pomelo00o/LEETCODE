/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        // recursive way
        if (!head || !head->next) return head;
        ListNode* n = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return n;

        // iterative way
        ListNode* curr = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = curr;
            curr = head;
            head = next;
        }
        return curr;
    }
};

