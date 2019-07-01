/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        stack<int> m;
        stack<int> n;
        while (l1) {
            m.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            n.push(l2->val);
            l2 = l2->next;
        }
        auto carry = 0;
        while (!m.empty() || !n.empty() || carry) {
            int a, b = 0;
            if (m.empty()) {
                a = 0;
            } else {
                a = m.top();
                m.pop();
            }
            if (n.empty()) {
                b = 0;
            } else {
                b = n.top();
                n.pop();
            }
            auto sum = a + b + carry;
            carry = sum / 10;
            ListNode* nextNode = new ListNode(sum % 10);
            nextNode->next = head->next;
            head->next = nextNode;
        }
        return head->next;
    }
};

