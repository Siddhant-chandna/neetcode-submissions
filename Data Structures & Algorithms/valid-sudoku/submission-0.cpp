class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(board.size(), vector<int> (board[0].size(),false));
        vector<vector<int>> cols(board.size(), vector<int> (board[0].size(),false));
        vector<vector<int>> boxes(board.size(), vector<int> (board[0].size(),false));

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                else{
                    int num=board[i][j]-'1';
                    int boxIdx=(i/3)*3+(j/3);
                    if(rows[i][num] || cols[j][num] || boxes[boxIdx][num]) return false;
                    rows[i][num]=cols[j][num]=boxes[boxIdx][num]=true;
                }
            }
        }
        return true;
    }
};
