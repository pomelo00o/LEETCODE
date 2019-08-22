/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node *curr = head;
        while (curr) {
            if (curr->child) {
                Node* next = curr->next;
                Node* child = flatten(curr->child);
                Node* last = child;
                while (last->next)
                    last = last->next;
                child->prev = curr;
                curr->next = child;
                curr->child = nullptr;
                last->next = next;
                if (next)
                    next->prev = last;
            }
            curr = curr->next;
        }
        return head;
    }
};

