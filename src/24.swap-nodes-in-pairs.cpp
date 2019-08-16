/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        // recursive way
        if (!head || !(head->next)) return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;

        // iterative way
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        /*
            see https://www.jianshu.com/p/bd4dc088e97a for more info
        */
        while (prev->next && prev->next->next) {
            ListNode* temp = prev->next->next;
            prev->next->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            prev = temp->next;
        }
        return dummy->next;
    }
};

