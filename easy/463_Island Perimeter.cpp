class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // matrix
        // time complexity: O(mn), space complexity: O(1)
        // 72ms, beats 86.98%
        
        // Main idea:
        // Count all island block's number, and record adjacent edge's number (repeat).
        // The result is 4 * cnt - 2 * repeat
        int count = 0, repeat = 0, row = grid.size(), col = row == 0 ? 0 : grid[0].size();
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j]) {
                    count++;
                    if(i > 0 && grid[i - 1][j]) { repeat++; }
                    if(j > 0 && grid[i][j - 1]) { repeat++; }
                }
            }
        }
        return 4 * count - 2 * repeat;
    }
};