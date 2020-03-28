class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in_stack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (in_stack.empty() && out_stack.empty()) {
            return 0;
        }
        if (!out_stack.empty()) {
            int num = out_stack.top();
            out_stack.pop();
            return num;
        } else {
            while(!in_stack.empty()) {
                int num = in_stack.top();
                in_stack.pop();
                out_stack.push(num);
            }
            int num = out_stack.top();
            out_stack.pop();
            return num;
        }
    }

    /** Get the front element. */
    int peek() {
        if (in_stack.empty() && out_stack.empty()) {
            return 0;
        }
        if (!out_stack.empty()) {
            int num = out_stack.top();
            return num;
        } else {
            while(!in_stack.empty()) {
                int num = in_stack.top();
                in_stack.pop();
                out_stack.push(num);
            }
            int num = out_stack.top();
            return num;
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (in_stack.empty() && out_stack.empty());
    }
    stack<int> in_stack;
    stack<int> out_stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */