class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int topp;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        topp=q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return topp;
    }
    
    int top() {
        int topp;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        topp=q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(topp);
        return topp;
    }
    
    bool empty() {
        if(q1.size()==0) return true;
        else return false;
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