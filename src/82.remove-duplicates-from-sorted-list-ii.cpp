/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) return head;
        auto val = head->val;
        auto p = head->next;
        if (p->val != val) {
            head->next = deleteDuplicates(p);
            return head;
        } else {
            while (p->val == val) {
                p = p->next;
            }
            return deleteDuplicates(p);
        }
    }
};

