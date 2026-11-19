class Solution {
public:
    int primsAlgo(int n, vector<vector<tuple<int,int,int>>> &adj, vector<vector<int>> &edges, int skipEdge, int forcedEdge){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> vis(n, 0);
        int sum=0,count=0;
        if(forcedEdge==-1){
            q.push({0,0});
        } else{
            int u=edges[forcedEdge][0];
            int v=edges[forcedEdge][1];
            int w=edges[forcedEdge][2];
            vis[u]=1;
            vis[v]=1;
            sum=w;
            count=2;
            for(auto [next, cost, idx]: adj[u]){
                if(idx!=skipEdge && !vis[next]) q.push({cost, next});
            }
            for(auto [next, cost, idx]: adj[v]){
                if(idx!=skipEdge && !vis[next]) q.push({cost, next});
            }
        }
        while(!q.empty() && count<n){
            auto [wt, node]=q.top();
            q.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            count++;
            for(auto [next, cost, idx]: adj[node]){
                if(idx==skipEdge || vis[next]) continue;
                q.push({cost, next});
            }
        }
        if(count!=n) return INT_MAX;
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int,int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w,i});
            adj[v].push_back({u,w,i});
        }
        int original=primsAlgo(n, adj, edges, -1, -1);
        vector<int> critical;
        vector<int> pseudoCritical;
        for(int i=0;i<edges.size();i++){
            int without=primsAlgo(n, adj, edges, i, -1);
            if(original<without){
                critical.push_back(i);
            } else{
                int with=primsAlgo(n, adj, edges, -1, i);
                if(with==original){
                    pseudoCritical.push_back(i);
                }
            }
        }
        return {critical, pseudoCritical};
    }
};