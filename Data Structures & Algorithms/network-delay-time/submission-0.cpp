class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            int d=x.first;
            int node=x.second;
            if(d>dist[node]) continue;
            for(auto [next, weight]:adj[node]){
                if(d+weight<dist[next]){
                    dist[next]=d+weight;
                    q.push({dist[next], next});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans, dist[i]);
        }
        return ans;
    }
};
