class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // BFS & DP

        // DP
        // time complexity: O(mn), space complexity: O(mn)
        // 176ms, beats 94.24%
        
        // Main idea:
        // Two pass, one from front to back, and another from back to front.
        // In each comparison, res[i][j] = min{res[i][j], res[i+-1][j+-1]} if applicable.
        
        int M = matrix.size();
        int N = matrix[0].size();
        
        vector<vector<int>> res(M, vector<int>(N, M + N));
        
        // From front to back
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(matrix[i][j] == 0) res[i][j] = 0;
                else {
                    if(i > 0) res[i][j] = min(res[i][j], res[i-1][j] + 1);
                    if(j > 0) res[i][j] = min(res[i][j], res[i][j-1] + 1);
                }
            }
        }
        
        // From back to front
        for(int i =  M - 1; i >= 0; --i) {
            for(int j = N - 1; j >= 0; --j) {
                if(i < M - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                if(j < N - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1);
            }
        }
        
        return res;
        
        
        // BFS
        // 380ms, beats 8.14%
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> res(M, vector<int>(N, -1));
        queue<vector<int>> q;
        int dir[5] = {1, 0, -1, 0, 1};
        
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(matrix[i][j] == 0) q.push({i, j, 0});
            }
        }
        
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur[0], y = cur[1];
            if(res[x][y] != -1) continue;
            res[x][y] = cur[2];
            for(int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if(nx < 0 || nx >= M || ny < 0 || ny >= N || res[nx][ny] != -1) continue;
                q.push({nx, ny, cur[2] + 1});
            }
        }
        return res;
    }
};