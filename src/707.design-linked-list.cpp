/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */
struct Node {
    int val;
    Node* next;
    Node(int v, Node* n) {
        this->val = v;
        this->next = n;
    }
};

class MyLinkedList {
private:
    Node* head;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head;
        for (int i = 0; i < index; ++i) curr = curr->next;
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        size++;
        Node *n = new Node(val, head);
        head = n;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        size++;
        Node* curr = head;
        while (curr->next) curr = curr->next;
        Node *n = new Node(val, nullptr);
        curr->next = n;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        // a test bug: if index < 0 ==> addAtHead(val)
        if (index < 0) {
            addAtHead(val);
            return;
        }
        if (index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        size ++;
        Node* curr = head;
        for (int i = 1; i < index; ++i) curr = curr->next;
        Node* n = new Node(val, curr->next);
        curr->next = n;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        size --;
        if (index == 0) {
            head = head->next;
            return;
        }
        Node* curr = head;
        for (int i = 1; i < index; ++i) curr = curr->next;
        curr->next = curr->next->next;
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