class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp
        // time complexity: O(mn), space complexity: O(mn)
        // 8ms, beats 99.39%
        
        // dp[i][j] means longest common subsequence between text1[0~i-1] and text2[0~j-1]
        // optimal substructure:
        //   1) match (text1[i-1]==text2[j-1]): dp[i][j]=1+dp[i-1][j-1]
        //   2) not match: dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        
        int m = text1.length(), n = text2.length();
        if(m < n) return longestCommonSubsequence(text2, text1);
        int dp[m + 1][n + 1];
        
        // initialization
        for(int i = 0; i <= m; ++i) dp[i][0] = 0;
        for(int i = 1; i <= n; ++i) dp[0][i] = 0;
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
        
        // Optimize space complexity to min(m, n):
        // Because we only use last `i` row.
        /*
        vector<vector<short>> m(2, vector<short>(b.size() + 1));
        for (auto i = 1; i <= a.size(); ++i)
            for (auto j = 1; j <= b.size(); ++j)
                if (a[i - 1] == b[j - 1]) m[i % 2][j] = m[(i -1) % 2][j - 1] + 1;
                else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);
        return m[a.size() % 2][b.size()];
        */
    }
};