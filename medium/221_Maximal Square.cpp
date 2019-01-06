class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dynamic programming
        // time complexity: O(n^2), space complexity: O(1)
        // 20ms, beats 54.85%
        
        // define dp[i][j] as the maximal length of the square that can be achieved at point (i, j)
        int row = matrix.size(), col = (row == 0 ? 0 : matrix[0].size()), res = 0;
        if(col == 0) { return 0; }
        
        // initial
        for(int i = 0; i < row; i++) {
            if(matrix[i][0] == '1') { 
                res = 1;
                break;
            }
        }
        if(res == 0) {
            for(int j = 0; j < col; j++) {
                if(matrix[0][j] == '1') { 
                    res = 1;
                    break;
                }
            }
        }
        
        // DP part
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == '1') {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                    res = max(res, matrix[i][j] - '0');
                }
            }
        }
        return res * res;
    }
};