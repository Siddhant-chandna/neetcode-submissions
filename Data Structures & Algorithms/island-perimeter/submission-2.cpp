class Solution {
public: 
    void trav(vector<vector<int>>& grid, int &ans, int i, int j){
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size() || grid[i][j]==0){
            ans++; 
            return;
        }
        if(grid[i][j]==-1) return;
        grid[i][j]=-1;
        trav(grid,ans,i-1,j);
        trav(grid,ans,i,j-1);
        trav(grid,ans,i+1,j);
        trav(grid,ans,i,j+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    trav(grid, ans, i,j);
                }
            }
        }
        return ans;
    }
};