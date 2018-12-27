class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // array
        // time complexity: O(n)
        // 8ms, beats 97.52%
        
        // search from right top corner, either go down or go left 
        int row = matrix.size(), col = (row == 0 ? 0 : matrix[0].size());
        if(col == 0) { return false; }
        
        int i = 0, j = col - 1;
        while(i < row && j >= 0) {
            if(matrix[i][j] == target) { 
                return true; 
            } else if(matrix[i][j] > target) {  // too large, search left
                j--;
            } else if(matrix[i][j] < target) {  // too small, search down
                i++;
            }
        }
        return false;
    }
};