class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {//dfs
        solveSudoku(board,0,0);
    }
    
    bool solveSudoku(vector<vector<char>>& board, int i, int j){
        if(i==9) return true;
        if(j==9) return solveSudoku(board,i+1,0);
        if(board[i][j]!='.') return solveSudoku(board,i,j+1);
        
        for(char ch='1';ch<='9';ch++){
            if(check(board,i,j,ch)){
                board[i][j]=ch;
                if(solveSudoku(board,i,j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    
    bool check(vector<vector<char>>& board, int i, int j, char val){
        int row=i-i%3, col=j-j%3;
        for(int x=0;x<9;x++) if(board[x][j]==val || board[i][x]==val) return false;
        for(int x=0;x<3;x++)
            for(int y=0;y<3;y++)
                if(board[row+x][col+y]==val) return false;
        return true;
    }
};