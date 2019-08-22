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

    ListNode* helper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid + 1, end);
        return merge(left, right);
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

