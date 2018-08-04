class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { //2D_array_flag
        int used_row[9][9]={0},used_col[9][9]={0},used_block[9][9]={0},num=0,k=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    num=board[i][j]-'1';
                    k=i/3*3+j/3;
                    if(used_row[i][num]|| used_col[j][num] || used_block[k][num])
                        return false;
                    else
                        used_row[i][num]=used_col[j][num]=used_block[k][num]=1;
                }
            }
        }
        return true;
    }
};