class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // array & DFS
        // time complexity: O(n^2)
        // 16ms, beats 90.92%
        
        // dfs, use const char* to manipulate target string more convenient (word + 1)
        int row = board.size(), col = (row == 0 ? 0 : board[0].size());
        if(col == 0) { return false; }
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(checkWord(board, word.c_str(), i, j, row, col)) { return true; }
            }
        }
        return false;
    }
    
    // DFS part
    bool checkWord(vector<vector<char>>& board, const char* word, int i, int j, int row, int col) {
        if(*word == '\0') { // if reach the end of the word, then find it
            return true; 
        } else if(i < 0 || i == row || j < 0 || j == col || board[i][j] != *word || board[i][j] == '0') { 
            return false; 
        }

        board[i][j] = '0';
        if(checkWord(board, word + 1, i + 1, j, row, col) || checkWord(board, word + 1, i, j + 1, row, col) || checkWord(board, word + 1, i - 1, j, row, col) || checkWord(board, word + 1, i, j - 1, row, col)) {
            return true;
        }

        board[i][j] = *word;
        return false;
    }
};