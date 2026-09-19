class MyCircularQueue {
public:
    stack<int> s1,s2;
    int count=0;
    MyCircularQueue(int k) {
        count=k;
    }
    
    bool enQueue(int value) {
        if(s1.size()<count){
            s1.push(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(s1.size()==0) return false;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return true;
    }
    
    int Front() {
        if(s1.empty()) return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    int Rear() {
        return !s1.empty()?s1.top():-1;
    }
    
    bool isEmpty() {
        return s1.empty();
    }
    
    bool isFull() {
        return s1.size()==count;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */