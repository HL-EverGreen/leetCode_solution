class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // DFS & backtracking
        // time complexity: O(n^n), space complexity: O(n^2) with O(n) in stack space
        // 4ms, beats 99.63%
        
        vector<vector<string>> res;
        vector<string> sol(n, string(n, '.'));
        solveNQueens(res, sol, 0, n);
        return res;
    }
    
    void solveNQueens(vector<vector<string>>& res, vector<string>& sol, int cur_row, int n) {
        if(cur_row == n) {
            res.push_back(sol);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isValid(sol, cur_row, col, n)) {         // if valid, continue search. after that recover the sol
                sol[cur_row][col] = 'Q';
                solveNQueens(res, sol, cur_row + 1, n);
                sol[cur_row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& sol, int row, int col, int n) {
        for(int i = 0; i < row; i++) {
            if(sol[i][col] == 'Q') { return false; }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(sol[i][j] == 'Q') { return false; }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if(sol[i][j] == 'Q') { return false; }
        }
        return true;
    }
};