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
        ListNode* dummy = new ListNode(-1), *curr = dummy;
        dummy->next = head;
        int cnt = 0;
        // to avoid TLE, reduce k to be k % n
        while (curr->next) {
            cnt++;
            curr = curr->next;
        }
        k %= cnt;
        curr = dummy;
        for (int i = 0; i < k; ++i) {
            ListNode* sec_tail = curr;
            while (sec_tail && sec_tail->next && sec_tail->next->next)
                sec_tail = sec_tail->next;
            ListNode* tail = sec_tail->next;
            sec_tail->next = nullptr;
            tail->next = curr->next;
            curr->next = tail;
        }
        return dummy->next;
    }
};

