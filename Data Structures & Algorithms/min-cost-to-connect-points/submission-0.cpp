class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0, 0});
        int n=points.size();
        vector<int> vis(n, 0);
        int sum=0;
        int count=0;
        while(!q.empty() && count<n){
            auto [wt, node]=q.top();
            q.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            count++;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                int dist= abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                q.push({dist, i});
            }
        }
        return sum;
    }
};
