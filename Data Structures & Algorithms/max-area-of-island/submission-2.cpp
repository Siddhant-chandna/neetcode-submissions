class Solution {
public:
    void trav(int i,int j,int &count, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return;
        grid[i][j]=0;
        count++;
        trav(i+1, j, count, grid);
        trav(i, j+1, count, grid);
        trav(i-1, j, count, grid);
        trav(i, j-1, count, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int count=0;
                    trav(i, j, count, grid);
                    ans=max(ans, count);
                }
            }
        }
        return ans;
    }
};
