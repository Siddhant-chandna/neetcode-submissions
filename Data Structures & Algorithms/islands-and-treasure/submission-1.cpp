class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> dist={{1,0},{0,1},{-1,0},{0,-1}};
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto x:dist){
                int ni=i+x[0];
                int nj=j+x[1];

                if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
                if(grid[ni][nj]!=INT_MAX) continue;
                grid[ni][nj]=grid[i][j]+1;
                q.push({ni,nj});
            }
        }
    }
};
