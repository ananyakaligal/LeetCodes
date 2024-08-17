#include <queue>

class MyStack {
    std::queue<int> one, two;

public:
    // Constructor
    MyStack() {}

    // Push element x onto the stack
    void push(int x) {
        one.push(x);
    }

    // Remove the element on the top of the stack and return it
    int pop() {
        int x = one.back();
        while (!one.empty()) {
            if (one.front() == one.back()) {
                one.pop();
            } else {
                two.push(one.front());
                one.pop();
            }
        }
        while (!two.empty()) {
            one.push(two.front());
            two.pop();
        }

        return x;
    }

    // Get the top element of the stack
    int top() {
        return one.back();
    }

    // Return whether the stack is empty
    bool empty() {
        return one.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
