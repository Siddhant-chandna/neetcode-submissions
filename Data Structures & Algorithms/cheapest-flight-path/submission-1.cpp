class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:flights){
            adj[x[0]].push_back({x[1], x[2]});
        }
        // flights taken, node, cost
        queue<tuple<int,int,int>> q;
        q.push({0, src, 0});
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto [flightsTaken, node, cost]=q.front();
            q.pop();
            if(flightsTaken>k) continue;
            for(auto [next, price]: adj[node]){
                int newCost=cost+price;
                if(newCost<dist[next]){
                    dist[next]=newCost;
                    q.push({flightsTaken+1, next, dist[next]});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
