class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // DFS
        // 4ms, beats 97.01%
        
        // Main idea:
        // Track remaining blocks when using DFS.
        // And return current possible number of paths in each DFS round.
        int row = grid.size(), col = grid[0].size(), ix, iy, cnt = 0;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {               // Set up starting point
                    ix = i;
                    iy = j;
                } else if(grid[i][j] != -1) {       // Count number of all '0' and '2'
                    cnt++;
                }
            }
        }
        
        return dfs(grid, ix, iy, cnt);
    }
    
    /* DFS part */
    int dfs(vector<vector<int>>& grid, int x, int y, int remain_blk) {
        /* Inlegal index or already visited in current branch */
        if(x < 0 || x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] == -1) { return 0; }

        /* Reach end point, check whether have gone through all blocks */
        if(grid[x][y] == 2) { return !remain_blk; }

        /* Set current val to -1 and do DFS. Then recover the value */
        grid[x][y] = -1;
        int cur_paths = dfs(grid, x - 1, y, remain_blk - 1) + dfs(grid, x + 1, y, remain_blk - 1) +
                        dfs(grid, x, y - 1, remain_blk - 1) + dfs(grid, x, y + 1, remain_blk - 1);
        grid[x][y] = 0;
        return cur_paths;
    }
};