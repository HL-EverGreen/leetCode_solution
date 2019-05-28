class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        // matrix
        // time complexity: O(n^2), space complexity: O(1)
        // 8ms, beats 94.02%
        
        // Main idea:
        // Straight forward, find maximum value in each row and col, and floor layer with 1 if occupied.
        int size = grid.size(), res = 0;
        
        /* Row */
        for(int i = 0, cur = 0; i < size; i++, res += cur, cur = 0) {
            for(int j = 0; j < size; j++) {
                cur = max(cur, grid[i][j]);
            }
        }
        
        /* Col and floor */
        for(int i = 0, cur = 0; i < size; i++, res += cur, cur = 0) {
            for(int j = 0; j < size; j++) {
                cur = max(cur, grid[j][i]);
                res += grid[j][i] ? 1 : 0;
            }
        }
        
        return res;
    }
};