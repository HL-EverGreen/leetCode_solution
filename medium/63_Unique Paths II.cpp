class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // array & DP
        // time complexity: O(n^2)
        // 0ms, beats 100.00%
        
        // the main idea is that dp[i][j]=dp[i+1][j]+dp[i][j+1]; if dp[i+1][j] or dp[i][j+1] has obstacle, just use 0 when add up
        int row = obstacleGrid.size(), col = (row == 0 ? 0 : obstacleGrid[0].size());
        if(col == 0) { return 0; }
        // check if obstacle located in start point or end point
        if(obstacleGrid[row - 1][col - 1] == 1 || obstacleGrid[0][0] == 1) { return 0; }
        
        for(int cur_row = row - 1; cur_row >= 0; cur_row--) {
            for(int cur_col = col - 1; cur_col >= 0; cur_col--) {
                if(obstacleGrid[cur_row][cur_col] == 1) {
                    obstacleGrid[cur_row][cur_col] = -1; //use -1 to present obstacle instead of 1
                    continue;
                }
                if(cur_row == row - 1 && cur_col == col - 1) { 
                    obstacleGrid[cur_row][cur_col] = 1; 
                } else if(cur_row == row - 1) { 
                    obstacleGrid[cur_row][cur_col] = (obstacleGrid[cur_row][cur_col + 1] == -1 ? 0 : obstacleGrid[cur_row][cur_col + 1]); 
                } else if(cur_col == col - 1) { 
                    obstacleGrid[cur_row][cur_col] = (obstacleGrid[cur_row + 1][cur_col] == -1 ? 0 : obstacleGrid[cur_row + 1][cur_col]); 
                } else { 
                    obstacleGrid[cur_row][cur_col] = (obstacleGrid[cur_row][cur_col + 1] == -1 ? 0 : obstacleGrid[cur_row][cur_col + 1]) + (obstacleGrid[cur_row + 1][cur_col] == -1 ? 0 : obstacleGrid[cur_row + 1][cur_col]); 
                }
            }
        }
        return obstacleGrid[0][0];
    }
};