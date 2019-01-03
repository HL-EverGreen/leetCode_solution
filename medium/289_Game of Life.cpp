class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // array
        // time complexity: O(n^2), space complexity: O(1)
        // 0ms, beats 100%
        
        // use two bits to solve this problem in-place
        // 1st bit: current status
        // 2nd bit: future status
        int row = board.size(), col = (row == 0) ? 0 : board[0].size();
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int liv_level = 0;
                
                for(int i_x = max(i - 1, 0); i_x < min(i + 2, row); i_x++) {            // use max(),min() to address the border problem
                    for(int i_y = max(j - 1, 0); i_y < min(j + 2, col); i_y++) {
                        liv_level += board[i_x][i_y] & 1;                               
                    }
                }
                
                if(liv_level == 3 || liv_level - board[i][j] == 3) {
                    board[i][j] |= 2;
                }
            }
        }
        
         for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                board[i][j] >>= 1;                                                      // update second bit to first bit (future state to current state)
            }
         }
    }
};