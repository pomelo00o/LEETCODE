/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        stack<int> stk;
        while (curr) {
            stk.push(curr->val);
            curr = curr->next;
        }
        while (head) {
            int v = stk.top();
            stk.pop();
            if (v != head->val)
                return false;
            head = head->next;
        }
        return true;
    }
};

