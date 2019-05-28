class Solution {
public:
    vector<int> dir{1, 0, -1, 0, 1};
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // BFS
        // time complexity: O(n^2), space complexity: O(n^2)
        // 116ms, beats 71.56%
        
        // Main idea:
        // Basic BFS.
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push({r0, c0});
        visited[r0][c0] = true;
        
        while(!q.empty()) {
            vector<int> cur = q.front();
            res.push_back(cur);
            q.pop();
            
            /* Branch four directions */
            for(int i = 0; i < 4; i++) {
                int nr = cur[0] + dir[i], nc = cur[1] + dir[i + 1];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;   
                }
            }
        }
        return res;
    }
};