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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> ptr_vec;
        while (head) {
            ListNode* temp = head;
            ptr_vec.push_back(temp);
            head = head->next;
        }
        int idx = ptr_vec.size() - n;
        if (idx == 0) {
            head = ptr_vec[0]->next;
        } else if (idx == ptr_vec.size() - 1) {
            head = ptr_vec[0];
            ptr_vec[idx - 1]->next = nullptr;
        } else {
            head = ptr_vec[0];
            ptr_vec[idx - 1]->next = ptr_vec[idx + 1];
        }
        delete ptr_vec[idx];
        return head;
    }
};