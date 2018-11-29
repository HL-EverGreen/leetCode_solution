class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // BFS
        // time complexity: O(n^2)
        // 12ms, beats 99%
        // first check elements on four boarders, if 'O', do BFS and flip all its neighbours into 'T'
        // travese the matrix and flip all 'O' into 'X' and all 'T' into 'O'
        
        
        int row_size = board.size(), col_size = (row_size == 0 ? 0 : board[0].size());
        
        // need not to use exit(0) because it won't pass Leetcode's testcase
        // if(col_size == 0) { exit(0);}
        
        // check elements on four boarders first
        for(int rowIdx = 0; rowIdx < row_size; rowIdx++) {
            if(board[rowIdx][0] == 'O') {
                check(board, rowIdx, 0, row_size, col_size);
            }
            if(board[rowIdx][col_size - 1] == 'O') {
                check(board, rowIdx, col_size - 1, row_size, col_size);
            }
        }
        
        for(int colIdx = 0; colIdx < col_size; colIdx++) {
            if(board[0][colIdx] == 'O') {
                check(board, 0, colIdx, row_size, col_size);
            }
            if(board[row_size - 1][colIdx] == 'O') {
                check(board, row_size - 1, colIdx, row_size, col_size);
            }
        }
        
        // flip the whole matrix
        for(auto& row:board) {
            for(auto& elem:row) {
                if(elem == 'T') { 
                    elem = 'O';
                }
                else if(elem == 'O') {
                    elem = 'X';
                }
            }
        }
    }
    
    // BFS
    void check(vector<vector<char>>& board, int i, int j, int row_size, int col_size) {
        board[i][j] = 'T';
        if(i > 0 && board[i - 1][j] == 'O') {
            check(board, i - 1, j, row_size, col_size);
        }
        if(i < row_size - 1 && board[i + 1][j] == 'O') {
            check(board, i + 1, j, row_size, col_size);
        }
        if(j > 0 && board[i][j - 1] == 'O') {
            check(board, i, j - 1, row_size, col_size);
        }
        if(j < col_size - 1 && board[i][j + 1] == 'O') {
            check(board, i, j + 1, row_size, col_size);
        }
    }
};