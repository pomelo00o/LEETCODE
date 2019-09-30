/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists, 0, lists.size() - 1);
    }

    ListNode* helper(vector<ListNode*>& lists, int s, int e) {
        if (s > e) return nullptr;
        if (s == e) return lists[s];
        int mid = s + (e - s) / 2;
        ListNode* l1 = helper(lists, s, mid);
        ListNode* l2 = helper(lists, mid + 1, e);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* dummy = new ListNode(-1), *curr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (!l1) curr->next = l2;
        if (!l2) curr->next = l1;
        return dummy->next;
    }
};

