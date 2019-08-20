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
        ListNode* dummy = new ListNode(-1), *pre = dummy, *curr = pre;
        dummy->next = head;
        int cnt = 0;
        while (curr->next) {
            cnt++;
            curr = curr->next;
        }
        while (cnt >= k) {
            curr = pre->next;
            for (int i = 1; i < k; ++i) {
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;\
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = curr;
            cnt -= k;
        }
        // illustrate in the following draft
        // eg: 1 2 3 4 5    k = 3
        // add one dummy node in front: -1 1 2 3 4 5
        // at iter1: curr = 1, tmp = 2 ==> -1 2 1 3 4 5
        // at iter2: curr = 1, tmp = 3 ==> -1 3 2 1 4 5
        // thus reverse the beginning k nodes
        return dummy->next;
    }
};

