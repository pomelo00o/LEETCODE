/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int cnt = 0;
        while (curr && cnt != k) {
            curr = curr->next;
            cnt += 1;
        }
        if (cnt == k) {
            curr = reverseKGroup(curr, k);
            while (cnt > 0) {
                ListNode* tmp = head->next;
                head->next = curr;
                curr = head;
                head = tmp;
                cnt -= 1;
            }
            head = curr;
        }
        return head;
    }
};

