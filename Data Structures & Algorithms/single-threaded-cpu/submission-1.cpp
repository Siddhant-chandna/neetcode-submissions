class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> order;
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> q;
        for(int i=0;i<tasks.size();i++){
            q.push({{tasks[i][0], tasks[i][1]},i});
        } 
        vector<int> ans;
        order.push({q.top().first.second,q.top().second});
        int i=q.top().first.first;
        q.pop();
        while(!order.empty()){
            ans.push_back(order.top().second);
            i+=order.top().first;
            order.pop();
            while(!q.empty() && q.top().first.first<=i){
                order.push({q.top().first.second, q.top().second});
                q.pop();
            }
            if(order.empty() && !q.empty()){
                order.push({q.top().first.second,q.top().second});
                i=q.top().first.first;
                q.pop();
            }
        }
        return ans;
    }
};