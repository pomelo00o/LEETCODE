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
        ListNode* dummy = new ListNode(-1), *curr = dummy;
        curr->next = head;
        stack<int> st;
        while (curr->next) {
            st.push(curr->next->val);
            curr = curr->next;
        }
        while (!st.empty()) {
            int val = st.top();
            st.pop();
            if (val != head->val) return false;
            head = head->next;
        }
        return true;
    }
};

