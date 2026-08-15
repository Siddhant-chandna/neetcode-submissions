class StockSpanner {
public:
    stack<int> s1;
    stack<int> s2;
    StockSpanner() {
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
    }
    
    int next(int price) {
        int count=0;
        s1.push(price);
        while(!s1.empty() && s1.top()<=price){
            count++;
            s2.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */