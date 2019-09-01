class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        // DP
        // time complexity: O(mn), space complexity: O(mn), can optimized to O(min(m,n)) by using two row (i % 2 and (i - 1) % 2)
        // 4ms, beats 99.52%
        
        // Main idea:
        // Like longest common subsequence.
        // dp[i][j] means that maximum number of lines between A[0~i-1] and B[0~j-1]
        // Optimal substructure:
        //   1) if A[i - 1] == B[j - 1]: dp[i][j] = 1 + dp[i - 1][j - 1]     matched
        //   2) else: dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])             doesn't match, so discard either of A[i - 1] or B[j - 1]

        int m = A.size(), n = B.size();
        int dp[m + 1][n + 1];
        
        // fill_n: can only accept iterator, can't accept address
        // fill_n (OutputIterator first, Size n, const T& val);
        // but can use memset if using int dp[m][n]: memset(dp, 0, sizeof(dp));
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(A[i - 1] == B[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};