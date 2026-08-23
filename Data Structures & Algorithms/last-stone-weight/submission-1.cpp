class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> w;
        for(auto s:stones){
            w.push(s);
        }
        while(w.size()>1){
            int x=w.top();
            w.pop();
            int y=w.top();
            w.pop();
            if(x!=y){
                w.push(x-y);
            }
        }
        return w.size()==1?w.top():0;
    }
};
