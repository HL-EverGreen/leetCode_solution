class Solution {
public:
    int totalNQueens(int n) {
        // DFS & backtracking
        // time complexity: O(n^n), space complexity: O(n^2) with O(n) in stack space
        // 4ms, beats 89.95%
        
        // actually do not need to use vector<string> to store current situation, col[i], diag1[i] and diag2[i] is enough by presenting if ith col/diag1/diag2 has at least one Queen 
        
        vector<string> sol(n, string(n, '.'));
        int count = 0;
        solveNQueens(count, sol, 0, n);
        return count;
    }
    
    void solveNQueens(int& count, vector<string>& sol, int cur_row, int n) {
        if(cur_row == n) {
            count++;
            return;
        }
        for(int col = 0; col < n; col++) {
            if(isValid(sol, cur_row, col, n)) {         // if valid, continue search. after that recover the sol
                sol[cur_row][col] = 'Q';
                solveNQueens(count, sol, cur_row + 1, n);
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