class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // array
        // Constant space complexity
        // Time complexity: O(n^2)
        // 32ms, beats 100.00%
        
        // Main idea: store every coords of element 0 in first column and row
        // Because the state of row0 and the state of column0 would
        // occupy the same cell, I let it be the state of row0,
        // and use another variable "col0" for column0
        int row = matrix.size(), col = (row == 0 ? 0 : matrix[0].size());
        bool col_0 = false;
        
        if(col == 0) { return; }
        
        for(int i = 0; i < row; i++) {
            if(matrix[i][0] == 0) { col_0 = true; }    
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = row - 1; i >= 0; i--) {
            for(int j = col - 1; j > 0; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // be careful about the order, col_0 stuff must be done after other cols
            if(col_0) {
                matrix[i][0] = 0;
            }
        }
    }
};