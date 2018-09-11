class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) { //dfs
        row=board.size(), col=row?board[0].size():0;
        if(col==0) return false;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(isFound(board,word.c_str(),i,j)) return true;    //transfer const *char instead of string can save quantity of time
        return false;
    }
    
private:
    int row,col;
    bool isFound(vector<vector<char>>& board, const char* word, int x, int y){
        if(*word=='\0') return true;
        if(x<0 || x>=row || y<0 || y>=col || board[x][y]!=*word || board[x][y]=='0') return false;
        board[x][y]='0';
        if(isFound(board,word+1,x+1,y) || isFound(board,word+1,x-1,y) || isFound(board,word+1,x,y+1) || isFound(board,word+1,x,y-1)) return true;
        board[x][y]=*word;
        return false;
    }
};