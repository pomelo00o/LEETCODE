/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        // first step to do is to detect whether there is a cycle
        // the basic idea is to set a walker and a runner
        // if they meet ==> hasCycle = true

        // second step is to put the walker back to head
        // set them to speed one
        // next time they will meet at the intersection point
        if (!head || !head->next) return nullptr;
        ListNode* slow = head, *fast = head;

        bool isCyclic = false;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                isCyclic = true;
                break;
            }
        }

        if (!isCyclic) return nullptr;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

