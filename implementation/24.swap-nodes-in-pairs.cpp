/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (43.08%)
 * Total Accepted:    280.4K
 * Total Submissions: 650.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
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
        if (head == NULL || head->next == nullptr) {
            return head;
        }
        ListNode* first = head;
        ListNode* temp = NULL;
        head = head->next;
        while(first!=nullptr&&first->next!=nullptr){
            if(temp!=NULL){
                temp->next = first->next;
            }
            temp = first;
            first = first->next;
            temp->next = first->next;
            first->next = temp;
            first = temp->next;
        }
        return head;
    }
};

