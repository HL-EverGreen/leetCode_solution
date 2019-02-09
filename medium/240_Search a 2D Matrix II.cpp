class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // matrix
        // time complexity: O(n), n is the size of matrix
        // space complexity: O(1)
        // 60ms, beats 99%
        
        // main idea:
        // start from upper right: 1) equal, return true
        //                         2) less, move down
        //                         3) greater, move left
        
        if(matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size(), col = matrix[0].size(), i = 0, j = col - 1;
        while(i < row && j >= 0) {
            int cur = matrix[i][j];
            if(cur == target) return true;
            else if(cur > target) j--;
            else i++;
        }
        return false;
    }
};