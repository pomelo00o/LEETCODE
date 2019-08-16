/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if (!head || !(head->next)) return;
        ListNode *mid = find_middle(head);
        ListNode *right = mid->next;
        right = reverse(right);
        mid->next = nullptr;
        merge(head, right);
    }

    ListNode* find_middle(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        // recursive way
        if (!head || !(head->next)) return head;
        ListNode* n = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return n;

        // iterative way
        ListNode *prev = nullptr;
        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    void merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (l1 || l2) {
            if (l1) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            if (l2) {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
    }
};

