/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, nullptr);
        int cnt = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = root;
        while (dummy->next) {
            cnt++;
            dummy = dummy->next;
        }
        int avg = cnt / k, ext = cnt % k;
        // eg: cnt = 10, k = 3
        // ==> avg = 3, ext = 1
        for (int i = 0; i < k && root; ++i) {
            res[i] = root;
            int n = (i < ext) ? (avg + 1) : avg; 
            for (int j = 1; j < n; ++j) {
                root = root->next;
            }
            ListNode* tmp = root->next;
            root->next = nullptr;
            root = tmp;
        }
        return res;
    }
};

