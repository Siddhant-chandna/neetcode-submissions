class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int t=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int r=x.first;
            int c=x.second;
            if(r!=-1 && c!=-1){
                for(int i=0;i<4;i++){
                    int nextR=r+dx[i];
                    int nextC=c+dy[i];
                    if(nextR>=0 && nextR<grid.size() && nextC>=0 && nextC<grid[0].size()){
                        if(grid[nextR][nextC]==1){
                            q.push({nextR, nextC});
                            grid[nextR][nextC]=2;
                        }
                    }
                }
            } else{
                if(!q.empty()){
                    t++;
                    q.push({-1,-1});
                }
            }
        }
        for(auto x:grid){
            for(auto y:x){
                if(y==1) return -1;
            }
        }
        return t;
    }
};