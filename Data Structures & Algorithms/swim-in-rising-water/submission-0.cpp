class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // wt, r, c
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        vector<vector<int>> dist(n, vector<int> (m,INT_MAX));
        dist[0][0]=grid[0][0];
        q.push({grid[0][0], 0, 0});
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [wt, r, c]=q.top();
            q.pop();
            if(wt>dist[r][c]) continue;
            if(r==n-1 && c==m-1){
                return wt;
            }
            for(int i=0;i<4;i++){
                int newR=dr[i]+r;
                int newC=dc[i]+c;
                if(newR<0 || newR>=n || newC<0 || newC>=m) continue;
                int newWT=max(wt,grid[newR][newC]);
                if(newWT<dist[newR][newC]){
                    dist[newR][newC]=newWT;
                    q.push({newWT, newR, newC});
                }
            }
        }
        return 0;
    }
};
