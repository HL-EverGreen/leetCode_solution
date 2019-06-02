class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        // DFS
        // 12ms, beats 84.27%
        
        // Main idea:
        // Expand the original grid to 3 * size, and fill the blank where line exists with 1.
        // And do DFS as the same as counting the number of islands.
        int size = grid.size(), res = 0;
        vector<vector<int>> expanded_grid(3 * size, vector<int>(3 * size, 0));
        
        /* Fill block where line exists with 1 */
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(grid[i][j] == '/') {
                    expanded_grid[3 * i][3 * j + 2] = expanded_grid[3 * i + 1][3 * j + 1] = expanded_grid[3 * i + 2][3 * j] = 1;
                } else if(grid[i][j] == '\\') {
                    expanded_grid[3 * i][3 * j] = expanded_grid[3 * i + 1][3 * j + 1] = expanded_grid[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }
        
        /* Do DFS */
        for(int i = 0; i < 3 * size; i++) {
            for(int j = 0; j < 3 * size; j++) {
                if(expanded_grid[i][j] == 0) {
                    dfs(expanded_grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    /* DFS */
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] == 1) { return; }
        grid[i][j] = 1;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};