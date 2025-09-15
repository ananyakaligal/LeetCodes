// Last updated: 9/16/2025, 12:07:26 AM
class MyQueue {
    stack<int> one, two;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!one.empty()) {
            two.push(one.top());
            one.pop();
        }
        one.push(x);
        while(!two.empty()) {
            one.push(two.top());
            two.pop();
        }
    }
    
    int pop() {
        int num = one.top();
        one.pop();
        return num;
    }
    
    int peek() {
        return one.top();
    }
    
    bool empty() {
        return one.empty();
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