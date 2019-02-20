class Solution {
public:
    int superEggDrop(int K, int N) {
        // dp
        // 96ms, beats 40%
        // can use mathmatical way to solve it: binary search + check binomial coefficients of the mid
        
        // method 1:
        // dp[m][k] presents the maximum number of floors that we can check
        // m is the number of moves, k is the number of eggs
        // optimal substructure:
        // 1) drop a egg, egg breaks, can still check dp[move - 1][k - 1] floor
        // 2) drop a egg, egg doesn't break, can check dp[move - 1][k] floor
        // dp[move][k] = dp[move - 1][k] + dp[move - 1][k - 1] + 1;
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int move = 0;
        while(dp[move][K] < N) {
            move++;
            for(int k = 1; k <= K; k++) dp[move][k] = dp[move - 1][k] + dp[move - 1][k - 1] + 1;
        }
        return move;
        
        // method 2:
        // time complexity: O(KN^2)
        // kind of brute force, since check each possibility
        // dp[K][N] = 1 + max(dp[K - 1][i - 1],dp[K][N - i]) for i in 1...N.
        // Optimal substructure:
        // When we drop an egg from a floor x, there can be two cases (1) The egg breaks (2) The egg doesn’t break.
        // 1) If the egg breaks after dropping from xth floor, then we only need to check for floors lower than x with remaining eggs; so the problem reduces to x-1 floors and n-1 eggs
        // 2) If the egg doesn’t break after dropping from the xth floor, then we only need to check for floors higher than x; so the problem reduces to k-x floors and n eggs.
        
        /*
        vector<vector<int>> trials(K + 1, vector<int>(N + 1, 0));
        for(int i = 1; i <= N; i++) trials[1][i] = i;
        for(int i = 1; i <= K; i++) trials[i][1] = 1;
        for(int i = 2; i <= K; i++) {
            for(int j = 2; j <= N; j++) {
                trials[i][j] = INT_MAX;
                for(int m = 1; m <= j; m++) {
                    trials[i][j] = min(trials[i][j], 1 + max(trials[i - 1][m - 1], trials[i][j - m]));
                }
            }
        }
        return trials[K][N];
        */
    }
};