class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i=0;i<profits.size();i++){
            q.push({capital[i],profits[i]});
        }
        priority_queue<int> pq;
        while(k--){
            while(!q.empty() && q.top().first<=w){
                pq.push(q.top().second);
                q.pop();
            }
            if(pq.empty()) break;
            w=w+pq.top();
            pq.pop();
        }
        return w;
    }
};