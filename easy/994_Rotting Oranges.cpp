class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS
        // time complexity: O(n^2), space complexity: O(n^2)
        // 4ms, beats 96.69%
        
        // Main idea:
        // Use cnt to calculate total fresh fruit's number.
        // Use BFS to do calculation until queue is empty, when rot a fresh fruit, cnt--.
        // At last, if cnt == 0, return max(res, 0). (to avoid to return -1)

        int dir[5] = {1, 0, -1, 0, 1}, row = grid.size(), col = grid[0].size(), cnt = 0;
        queue<pair<int, int>> q;
        
        /* Push rotten fruit into queue and count fresh fruits number */
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                } else if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        
        /* BFS */
        int res = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto cur = q.front();
                int r = cur.first, c = cur.second;
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int nr = r + dir[j], nc = c + dir[j + 1];
                    if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1) {           // Fresh fruits
                        q.push(make_pair(nr, nc));
                        grid[nr][nc] = 2;
                        cnt--;
                    }
                }
            }
            res++;
        }
        
        return cnt == 0 ? max(res, 0) : -1;         // The reason using max(res, 0) is to avoid to return -1 directly
    }
};