class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;
        int fresh=0;
        queue<pair<int,int>> q;
        for(int j=0;j<grid.size();j++){
            for(int i=0;i<grid[0].size();i++){
                if(grid[j][i]==2) q.push({j,i});
                if(grid[j][i]==1) fresh++;
            }
        }
        q.push({-1,-1});
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
            if(i!=-1 && j!=-1){
                if(i-1 >= 0 && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                    fresh--;
                }
                if(i+1<grid.size() && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                    fresh--;
                }
                if(j-1 >= 0 && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                    fresh--;
                }
                if(j+1<grid[0].size() && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                    fresh--;
                }
            } else if(!q.empty()){
                t++;
                q.push({-1,-1});
            }
        }
        return fresh==0?t:-1;
    }
};
