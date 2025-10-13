class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
    
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.empty()) return;
        int v = st.top();
        st.pop();
        if(v == minSt.top() ) minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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