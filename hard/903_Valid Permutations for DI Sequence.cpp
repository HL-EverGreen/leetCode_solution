class Solution {
public:
    int numPermsDISequence(string S) {
        // DP
        // time complexity: O(n^2), space complexity: O(n^2)
        // 0ms, beats 100%
        
        // Main idea:
        // dp[i][j] presents the number of possible permutations of first i + 1 digits,
        // where the i + 1th digit is j + 1th smallest in the rest of digits.
        
        int n = S.length(), mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(S[i] == 'I') {
                for(int j = 0, cur = 0; j < n - i; j++) {
                    dp[i + 1][j] = cur = (cur + dp[i][j]) % mod;            // Since increasing, so equal to all j <= current j
                }
            } else {
                for(int j = n - i - 1, cur = 0; j >= 0; j--) {
                    dp[i + 1][j] = cur = (cur + dp[i][j + 1]) % mod;        // Since decreasing, so equal to all j > current j
                }
            }
        }
        return dp[n][0];
    }
};