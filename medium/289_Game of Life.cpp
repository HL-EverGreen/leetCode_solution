class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {//bit operation
        //use two bits to solve this problem in-place
        int row=board.size(),col=row?board[0].size():0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int liv_level=0;
                for(int i_x=max(i-1,0);i_x<min(i+2,row);i_x++){     //use max(),min() to address the border problem
                    for(int j_y=max(j-1,0);j_y<min(j+2,col);j_y++){
                        liv_level+=board[i_x][j_y]&1;               //use the current state to calculate
                    }
                }
                if(liv_level==3 || liv_level-board[i][j]==3)
                    board[i][j] |=2;                                //use two bits instead of one to present the next and current state
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                board[i][j]>>=1;
            }
        }
    }
};