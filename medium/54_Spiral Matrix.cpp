class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // array
        // time complexity: O(n^2), space complexity: O(n^2)
        // 0ms, beats 100%
        
        // since matrix's length may not equals to width, we have to add break condition in loop
        int row = matrix.size(), col = (row == 0 ? 0 : matrix[0].size());
        int row_start = 0, row_end = row - 1, col_start = 0, col_end = col - 1;
        vector<int> res;
        
        while(row_start <= row_end && col_start <= col_end) {
            for(int i = col_start; i <= col_end; i++) {     // upper row, from left to right
                res.push_back(matrix[row_start][i]);
            }
            if(++row_start == row_end + 1) { break; }
            
            for(int i = row_start; i <= row_end; i++) {     // right col, from top to down
                res.push_back(matrix[i][col_end]);
            }
            if(--col_end == col_start - 1) { break; }
            
            for(int i = col_end; i >= col_start; i--) {     // lower row, from right to left
                res.push_back(matrix[row_end][i]);
            }
            if(--row_end == row_start - 1) { break; }
            
            for(int i = row_end; i >= row_start; i--) {     // left col, from down to top
                res.push_back(matrix[i][col_start]);
            }
            if(++col_start == col_end + 1) { break; }
        }
        return res;
    }
};