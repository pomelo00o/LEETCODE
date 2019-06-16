class MyQueue {
private:
    stack<int> my_stack;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp;
        while (!my_stack.empty()) {
            temp.push(my_stack.top());
            my_stack.pop();
        }
        my_stack.push(x);
        while (!temp.empty()) {
            my_stack.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = my_stack.top();
        my_stack.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return my_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return my_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */