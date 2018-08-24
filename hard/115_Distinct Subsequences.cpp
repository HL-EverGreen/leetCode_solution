class Solution {
public:
    int numDistinct(string s, string t) {//dp
        //define its state dp[i][j] to be the number of distinct subsequences of t[0..i - 1] in s[0..j - 1]
        //General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
        //General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];
        //Boundary case 1: dp[0][j] = 1 for all j;
        //Boundary case 2: dp[i][0] = 0 for all positive i.
        
        //If t[i - 1] != s[j - 1], the distinct subsequences will not include s[j - 1] and thus all the number of distinct subsequences will simply be those in s[0..j - 2], which corresponds to dp[i][j - 1];
        //If t[i - 1] == s[j - 1], the number of distinct subsequences include two parts: those with s[j - 1] and those without;
        //An empty string will have exactly one subsequence in any string :-)
        //Non-empty string will have no subsequences in an empty string.

        int m = t.length(), n = s.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        return dp[m][n];
    }
};