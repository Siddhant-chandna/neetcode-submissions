class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int x=0;
    KthLargest(int k, vector<int>& nums) :x(k) {
        for(auto x:nums){
            add(x);
        }
    }
    
    int add(int val) {
        if(q.size()<x){
            q.push(val);
            return q.top();
        } else{
            if(val<=q.top()) return q.top();
            else{
                q.pop();
                q.push(val);
                return q.top();
            }
        }
        return -1;
    }
};
