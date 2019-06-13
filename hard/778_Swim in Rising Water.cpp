class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // priority_queue & binary search & DFS
        
        // method 1
        // priority queue
        // time complexity: O(n^2logn), space complexity: O(n^2)
        // 40ms, beats 40%
        
        // Main idea:
        // Use priority queue to push current block's height and position order from small to big.
        // Use cur_height to record max height occured.
        // When reach final block, return cur_height.
        /*
        int N = grid.size(), cur_height = max(grid[0][0], grid[N - 1][N - 1]);
        int dir[5] = {1, 0, -1, 0, 1};
        vector<vector<int>> visited(N, vector<int>(N, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cur_height, 0, 0});
        visited[0][0] = 1;
        while(!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            int r = cur[1], c = cur[2];
            cur_height = max(cur_height, cur[0]);
            if(r == N - 1 && c == N - 1) { return cur_height; }
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if(nr >= 0 && nr < N && nc >= 0 && nc < N && visited[nr][nc] == 0) {
                    visited[nr][nc] = 1;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return -1; // Can't reach here
        */
        
        // method 2
        // binary search + dfs
        // time complexity: O(n^2logn), space complexity: O(n^2)
        // 8ms, beats 100%
        
        // Main idea:
        // Use binary search to determine current height to try.
        // And use DFS to verify the assumption.
        int N = grid.size(), low = 0, high = N * N - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            vector<vector<int>> visited(N, vector<int>(N, 0));
            if(dfs(grid, visited, mid, 0, 0)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
    
    /* Verify whether cur_h is big enough to reach the end using DFS */
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int cur_h, int r, int c) {
        int N = grid.size();
        if(r < 0 || r >= N || c < 0 || c >= N || visited[r][c] || grid[r][c] > cur_h) { return false; }
        if(r == N - 1 && c == N - 1) { return true; }
        visited[r][c] = 1;
        return dfs(grid, visited, cur_h, r + 1, c) || dfs(grid, visited, cur_h, r - 1, c) ||
            dfs(grid, visited, cur_h, r, c + 1) || dfs(grid, visited, cur_h, r, c - 1);
    }
    
    
};