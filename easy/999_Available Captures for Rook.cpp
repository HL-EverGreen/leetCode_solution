class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // matrix
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Nothing to say.. Straight forward
        const int SIZE = 8;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                if(board[i][j] == 'R') {
                    return search(board, i, j, 1, 0) + search(board, i, j, -1, 0) +
                        search(board, i, j, 0, 1) + search(board, i, j, 0, -1);
                }
            }
        }
        return 0;
    }
    
    int search(vector<vector<char>>& board, int x, int y, int nx, int ny) {
        while(x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] != 'B') {
            if(board[x][y] == 'p') { return 1; }
            x += nx;
            y += ny;
        }
        return 0;
    }
};