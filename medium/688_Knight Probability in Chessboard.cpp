class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // DFS -> DP
        // time complexity: O(KN^2), space complexity: O(KN^2)
        // 4ms, beats 99.4%
        
        // Main idea:
        // Use valid[k][r][c] to present number of possibilities that remain in chessboard when 
        // starting at (r,c) with k remaining jump chance.
        // So use DFS with memorilization (similiar to DP) to accumulate all possibilities.

        vector<vector<vector<double>>> valid(K + 1, vector<vector<double>>(N, vector<double>(N, -1)));
        return dfs(valid, K, N, r, c) / pow(8, K);
    }
    
    double dfs(vector<vector<vector<double>>>& valid, int rem, const int& N, int r, int c) {
        if(r >= N || r < 0 || c >= N || c < 0) { return 0; }
        if (rem == 0) { return 1; }
        if(valid[rem][r][c] != -1) { return valid[rem][r][c]; }
        valid[rem][r][c] = 0;

        /* Branch into eight possibilities */
        for(int i = -2; i <= 2; i++) {
            if(i == 0) { continue; }
            valid[rem][r][c] += dfs(valid, rem - 1, N, r + i, c + 3 - abs(i))
                + dfs(valid, rem - 1, N, r + i, c + abs(i) - 3);
        }
        return valid[rem][r][c];
    }
};