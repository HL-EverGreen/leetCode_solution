class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // matrix
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 92.6%
        
        // Main idea:
        // Idea is to define upper left X as the head of battle ship.
        // We simply need to count the number of heads.
        int row = board.size(), col = (row ? board[0].size() : 0), res = 0;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                /* Only count head of the ship */
                res += (board[i][j] == 'X') && (i == 0 || board[i - 1][j] == '.')
                    && (j == 0 || board[i][j - 1] == '.');
            }
        }
        return res;
    }
};