/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* tail = head;
        int len = 0;
        while (tail) {
            tail = tail->next;
            len += 1;
        }
        tail->next = head;
        k = k % len;
        for (int i = 0; i < len - k; ++i) {
            tail = tail->next;
        }
        auto new_head = tail->next;
        tail->next = nullptr;
        return new_head;
    }
};

