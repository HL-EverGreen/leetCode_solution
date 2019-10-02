class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        // matrix
        // time complexity: O(n^3), space complexity: O(n^2)
        // 32ms, beats 36.87%
        
        // Main idea:
        // Use left and top to count max continuous 1.
        // Attempt from longest 边长, search for all possible positions. If exists square, return.
        
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> left(M, vector<int>(N)), top(M, vector<int>(N));
        
        // Calculate top and left matrix
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                if(grid[i][j] == 0) continue;
                left[i][j] = 1 + (j ? left[i][j - 1] : 0);
                top[i][j] = 1 + (i ? top[i - 1][j] : 0);
            }
        }
        
        // Loop from longest possible length
        for(int len = min(M, N); len > 0; --len) {
            for(int i = 0; i + len - 1 < M; ++i) {
                for(int j = 0; j + len - 1 < N; ++j) {
                    if(min({top[i + len - 1][j], top[i + len - 1][j + len - 1],
                           left[i][j + len - 1], left[i + len - 1][j + len - 1]}) >= len) return len * len; // Square
                }
            }
        }
        return 0;
    }
};