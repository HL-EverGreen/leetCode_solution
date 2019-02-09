class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // matrix & dfs
        // 24ms, beats 100%
        
        // main idea:
        // do dfs to each detected 1, compute this island's area (set -1 after computing)
        // compare all islands' area
        
        if(grid.empty() || grid[0].empty()) return 0;
        int res = 0, row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) res = max(res, areaOfThisIsland(grid, i, j));                   // keep the max area
            }
        }
        return res;
    }
    
    // DFS and compute island's area
    int areaOfThisIsland(vector<vector<int>>& grid, int row, int col) {
        int area = 1;
        int dir[5] = {1, 0, -1, 0, 1};
        grid[row][col] = -1;
        for(int i = 0; i < 4; i++) {
            int nr = row + dir[i], nc = col + dir[i + 1];
            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1) 
                area += areaOfThisIsland(grid, nr, nc); 
        }
        return area;
    }
};