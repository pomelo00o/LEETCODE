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
private:
    ListNode* helper(vector<ListNode*>& lists, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l = helper(lists, 0, mid);
        ListNode* r = helper(lists, mid + 1, right);
        return merge(l, r);
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        if (!l) return r;
        if (!r) return l;
        ListNode* dummy = new ListNode(-1), *curr = dummy;
        while (l && r) {
            if (l->val < r->val) {
                curr->next = l;
                l = l->next;
            } else {
                curr->next = r;
                r = r->next;
            }
            curr = curr->next;
        }
        if (!l) curr->next = r;
        if (!r) curr->next = l;
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists, 0, lists.size() - 1);
    }
};

