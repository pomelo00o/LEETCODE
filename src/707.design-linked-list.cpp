/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size = 0;
    Node* head = new Node(0);
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) return -1;
        Node* tmp = head->next;
        while (index) {
            tmp = tmp->next;
            index -= 1;
        }
        return tmp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* prevHead = head->next;
        Node* newHead = new Node(val);
        newHead->next = prevHead;
        head->next = newHead;
        size += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* tmp = head;
        while (tmp && tmp->next) {
            tmp = tmp->next;
        }
        Node* tail = new Node(val);
        tmp->next = tail;
        tail->next = nullptr;
        size += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        Node* prev = head;
        while (index) {
            prev = prev->next;
            index -= 1;
        }
        Node* node = new Node(val);
        Node* nextNode = prev->next;
        prev->next = node;
        prev->next->next = nextNode;
        size += 1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index > size) return;
        Node* prev = head;
        while (index) {
            prev = prev->next;
            index -= 1;
        }
        Node* curr = prev->next;
        prev->next = prev->next->next;
        size -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

