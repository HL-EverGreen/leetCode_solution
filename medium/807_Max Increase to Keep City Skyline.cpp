class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // Matrix
        // time complexity: O(n^2), space complexity: O(n)
        // Main idea: Traverse twice.
        // 1) First time record maximum value of each row and col.
        // 2) Second time use the smaller one among two maximum value to calculate result.
        
        int n = grid.size(), res = 0;
        if(!n) return 0;
        vector<int> maxRow(n), maxCol(n);
        
        // First pass to calculate maximum value of each col and row
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }
        
        // Second pass to calculate result
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                res += min(maxRow[i], maxCol[j]) - grid[i][j];
            }
        }
        return res;
    }
};