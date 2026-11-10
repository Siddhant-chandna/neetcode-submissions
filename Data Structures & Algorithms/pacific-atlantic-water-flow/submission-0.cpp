class Solution {
public:
    void dfsPacific(int i, int j, vector<vector<int>>& heights, vector<vector<char>> &pacific, int parent){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || pacific[i][j]=='P') return;
        if (parent > heights[i][j]) {
            return;
        }
        pacific[i][j]='P';
        dfsPacific(i+1,j,heights, pacific, heights[i][j]);
        dfsPacific(i,j+1,heights, pacific, heights[i][j]);
        dfsPacific(i-1,j,heights, pacific, heights[i][j]);
        dfsPacific(i,j-1,heights, pacific, heights[i][j]);
    }
    void dfsAtlantic(int i, int j, vector<vector<int>>& heights, vector<vector<char>> &atlantic, int parent){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size() || atlantic[i][j]=='A') return;
        if (parent > heights[i][j]) {
            return;
        }
        atlantic[i][j]='A';
        dfsAtlantic(i+1,j,heights, atlantic, heights[i][j]);
        dfsAtlantic(i,j+1,heights, atlantic, heights[i][j]);
        dfsAtlantic(i-1,j,heights, atlantic, heights[i][j]);
        dfsAtlantic(i,j-1,heights, atlantic, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<char>> pacific(n, vector<char> (m,'0'));
        vector<vector<char>> atlantic(n, vector<char> (m,'0'));
        vector<vector<int>> pacificAtlantic;
        for(int i=0;i<n;i++){
            dfsPacific(i,0, heights,pacific,-1);
        }
        for(int j=0;j<m;j++){
            dfsPacific(0,j, heights,pacific,-1);
        }
        for(int i=0;i<n;i++){
            dfsAtlantic(i,m-1, heights,atlantic,-1);
        }
        for(int j=0;j<m;j++){
            dfsAtlantic(n-1,j, heights,atlantic,-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]=='P' && atlantic[i][j]=='A'){
                    pacificAtlantic.push_back({i,j});
                }
            }
        }
        return pacificAtlantic;
    }
};
