class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // array & DP
        // time complexity: O(n^2)
        // 4ms, beats 100.00%
        
        // in-place modify, grid[i][j] += min(grid[i + 1][j], grid[i][j + 1])
        int row = grid.size(), col = (row == 0 ? 0 : grid[0].size());
        if(col == 0) return -1;
        
        for(int cur_row = row - 1; cur_row >= 0; cur_row--) {
            for(int cur_col = col - 1; cur_col >= 0; cur_col--) {
                if(cur_row == row - 1 && cur_col == col - 1) {
                    continue;
                } else if(cur_row == row - 1) {
                    grid[cur_row][cur_col] += grid[cur_row][cur_col + 1];
                } else if(cur_col == col - 1) {
                    grid[cur_row][cur_col] += grid[cur_row + 1][cur_col];
                } else {
                    grid[cur_row][cur_col] += min(grid[cur_row + 1][cur_col], grid[cur_row][cur_col + 1]);
                }
            }
        }
        return grid[0][0];
    }
};