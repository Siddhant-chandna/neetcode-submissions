class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        priority_queue<int> q;
        for(auto x:tasks){
            m[x]++;
        }
        for(auto x:m){
            q.push(x.second);
        }
        queue<pair<int,int>> cooldown;
        int t=0;
        while(!q.empty() || !cooldown.empty()){
            t++;
            if(!cooldown.empty()){
                auto [freq, timestamp]=cooldown.front();
                if(timestamp<=t){
                    cooldown.pop();
                    q.push(freq);
                }
            }
            if(!q.empty()){
                int max_freq=q.top();
                q.pop();
                if(max_freq>1){
                    cooldown.push({max_freq-1, t+n+1});
                }
            }
        }
        return t;
    }
};
