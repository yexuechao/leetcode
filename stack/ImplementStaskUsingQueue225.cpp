class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        nums.push(x);
        for (int i = 0; i < nums.size() - 1; i++) {
            int num = nums.front();
            nums.pop();
            nums.push(num);
        }
        return ;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (nums.empty()) {
            return 0;
        }
        int num = nums.front();
        nums.pop();
        return num;
    }

    /** Get the top element. */
    int top() {
        if (nums.empty()) {
            return 0;
        }
        return nums.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return nums.empty();
    }
    queue<int> nums;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */