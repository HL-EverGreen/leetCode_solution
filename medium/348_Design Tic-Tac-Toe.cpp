class TicTacToe {
public:
    /** Initialize your data structure here. */
    // matrix
    // time complexity: O(1), space complexity: O(n)
    // 44ms, beats 100%

    // main idea:
    // use row/col/diag/antidiag vector/int to see if the sum of this row/col/diag == n or -n, if ==, then someone wins
    
    TicTacToe(int n): rowJudge(n), colJudge(n), total(n), diag(0), anti(0) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
        rowJudge[row] += add;
        colJudge[col] += add;
        if(row == col) diag += add;
        if(row == total - col - 1) anti += add;
        
        if(abs(rowJudge[row]) == total || abs(colJudge[col]) == total || abs(diag) == total || abs(anti) == total)
            return player;
        return 0;
    }
    
private:
    vector<int> rowJudge;
    vector<int> colJudge;
    int total;
    int diag;
    int anti;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */