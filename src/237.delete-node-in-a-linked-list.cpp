/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
    void deleteNode(ListNode* node) {
        // fill the node with value node->next->val
        node->val = node->next->val;
        // delete node->next
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
    }
};

