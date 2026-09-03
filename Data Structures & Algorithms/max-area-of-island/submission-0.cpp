class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j,int &count,int &ans){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        count++;
        ans=max(ans, count);
        dfs(grid, i+1, j, count, ans);
        dfs(grid, i, j+1, count, ans);
        dfs(grid, i-1, j, count, ans);
        dfs(grid, i, j-1, count, ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(grid, i,j,count,ans);
                }
            }
        }
        return ans;
    }
};
