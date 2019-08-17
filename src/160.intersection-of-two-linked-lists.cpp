/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // suppose listA = A + (intersection), listB = B + (intersecton)
        // consider listC = A + (intersection) + B + (intersection), and
        // listD = B + (intersection) + A + (intersection)
        // they have same length ==> one while loop can solve the problem
        if (!headA || !headB) return nullptr;
        ListNode* a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

