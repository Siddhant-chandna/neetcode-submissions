class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        pre.resize(rows+1, vector<int> (cols+1));
        for(int row=1;row<=rows;row++){
            for(int col=1;col<=cols;col++){
                pre[row][col]=matrix[row-1][col-1]
                                + pre[row-1][col]
                                + pre[row][col-1]
                                - pre[row-1][col-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1]
                - pre[row1][col2+1]
                - pre[row2+1][col1]
                +pre[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */