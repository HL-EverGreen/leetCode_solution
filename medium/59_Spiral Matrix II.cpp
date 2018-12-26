class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // array
        // time complexity: O(n^2)
        // 0ms, beats 100.00%
        
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1, val = 1;
        
        while(row_start <= row_end && col_start <= col_end) {
            for(int i = col_start; i <= col_end; i++) {
                matrix[row_start][i] = val++;
            }
            row_start++;
            for(int i = row_start; i <= row_end; i++) {
                matrix[i][col_end] = val++;
            }
            col_end--;
            for(int i = col_end; i >= col_start; i--) {
                matrix[row_end][i] = val++;
            }
            row_end--;
            for(int i = row_end; i >= row_start; i--) {
                matrix[i][col_start] = val++;
            }
            col_start++;
        }
        return matrix;
    }
};