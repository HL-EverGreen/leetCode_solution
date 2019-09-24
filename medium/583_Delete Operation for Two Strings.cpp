class Solution {
public:
    int minDistance(string word1, string word2) {
        // DP
        // time complexity: O(mn), space complexity: O(mn)
        // 8ms, beats 99.06%
        
        // Main idea:
        // Similar to LC 1143: longest common subsequence (LCS).
        // The goal is to find the LCS and the res is m+n - 2*LCS
        // dp[i][j] represents LCS for word1[0~i-1] and word2[0~j-1]
        // *NOTICE: SPACE COMPLEXITY can also decrease to O(min(m,n)), see
        // LC 1143 for more detail.
        
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(word1[i - 1] == word2[j - 1]) {     // Match
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Not match, ignore either last char
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};