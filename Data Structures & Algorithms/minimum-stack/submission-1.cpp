class MinStack {
public:
    stack<int> s;
    stack<int> minStack; 
    MinStack() {}
    
    void push(int val) {
        if(minStack.empty() || val<=minStack.top()){
            minStack.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(!s.empty()){
            if(!minStack.empty() && s.top()==minStack.top()){
                minStack.pop();
            }
            s.pop();
        }
    }
    
    int top() {
        return !s.empty()?s.top():-1;
    }
    
    int getMin() {
        return !minStack.empty()?minStack.top():-1;
    }
};
