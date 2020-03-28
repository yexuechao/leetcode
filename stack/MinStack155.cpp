class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        common_stack.push(x);
        if (min_stack.empty()) {
            min_stack.push(x);
        } else {
            int min_num = min_stack.top();
            if (min_num <= x) {
                min_stack.push(min_num);
            } else {
                min_stack.push(x);
            }
        }
        return ;
    }

    void pop() {
        common_stack.pop();
        min_stack.pop();
    }

    int top() {
        return common_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
    stack<int> common_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */