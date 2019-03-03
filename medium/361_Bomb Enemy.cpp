class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        // geometry & matrix
        // time complexity: O(mn), space complexity: O(mn)
        // 40ms, beats 31.03%
        // Just like max sum subarray!!
        
        // main idea:
        // Use head and tail to record how many enemies are there in front of wall in current row/col from begin and end
        // When head and tail encounter at wall, reset to 0.
        // And count[i][j] represents how many enemies can kill if placing bomb at (i,j). count[i][j] can only add head and tail when grid[i][j] is '0'

        if(grid.empty() || grid[0].empty()) return 0;
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> count(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++) {                                                                      // calculate each block's max kill enemies in row
            for(int j = 0, head = 0, tail = 0; j < col; j++) {
                count[i][j] += (grid[i][j] == '0' ? head : 0);                                              // max kill from left
                count[i][col - 1 - j] += (grid[i][col - 1 - j] == '0' ? tail : 0);                          // max kill from right
                head = (grid[i][j] == 'W' ? 0 : (grid[i][j] == 'E' ? head + 1 : head));
                tail = (grid[i][col - 1 - j] == 'W' ? 0 : (grid[i][col - 1 - j] == 'E' ? tail + 1 : tail));
            }
        }
        
        for(int j = 0; j < col; j++) {                                                                      // then add max kill enemies in col
            for(int i = 0, head = 0, tail = 0; i < row; i++) {
                count[i][j] += (grid[i][j] == '0' ? head : 0);                                              // max kill from top
                count[row - 1 - i][j] += (grid[row - 1 - i][j] == '0' ? tail : 0);                          // max kill from bottom
                head = (grid[i][j] == 'W' ? 0 : (grid[i][j] == 'E' ? head + 1 : head));
                tail = (grid[row - 1 - i][j] == 'W' ? 0 : (grid[row - 1 - i][j] == 'E' ? tail + 1 : tail));
            }
        }
        
        int res = 0;
        for(auto& v : count) {                                                                              // find res
            for(auto& i : v) res = max(res, i);
        }
        return res;
    }
};