class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // matrix
        // time complexity: O(mn), space complexity: O(1)
        // 12ms, beats 93.78%
        
        // Main idea:
        // Straight forward.
        int row = matrix.size(), col = matrix[0].size();
        
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] != matrix[i - 1][j - 1]) { return false; }
            }
        }
        return true;
    }
};