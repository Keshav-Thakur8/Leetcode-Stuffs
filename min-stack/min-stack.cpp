class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> regular;
    stack<int> min_;
    MinStack() {
        
    }
    
    void push(int val) {
        regular.push(val);
        if(min_.empty()) {
            min_.push(val);
        }
        else {
            min_.push(min(min_.top(), val));
        }
    }
    
    void pop() {
        regular.pop();
        min_.pop();
    }
    
    int top() {
        return regular.top();
    }
    
    int getMin() {
        return min_.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */