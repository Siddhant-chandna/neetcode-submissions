class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m,INT_MAX));
        // effort, row col
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        q.push({0,0,0});
        dist[0][0]=0;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            auto [effort, r, c]=q.top();
            q.pop();
            if(effort>dist[r][c]) continue;
            if(r==n-1 && c==m-1){
                return effort;
            }
            for(int i=0;i<4;i++){
                int newR=r+dr[i];
                int newC=c+dc[i];
                if(newR<0 || newR>=n || newC<0 || newC>=m) continue;
                int newEffort=max(effort,abs(heights[r][c]-heights[newR][newC]));
                if(newEffort<dist[newR][newC]){
                    dist[newR][newC]=newEffort;
                    q.push({newEffort, newR, newC});
                }
            }
        }
        return 0;
    }
};
