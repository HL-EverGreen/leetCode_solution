class Solution {
public:
    int minDistance(string word1, string word2) {//dp
        //classic problem of DP
        //We define the state dp[i][j] to be the minimum number of operations to convert word1[0..i - 1] to word2[0..j - 1]
        //Consider word[i - 1] and word2[j - 1]. If they are euqal, then no more operation is needed and dp[i][j] = dp[i - 1][j - 1]
        //If they are not equal, we need to consider three cases:
        //Replace (dp[i][j] = dp[i - 1][j - 1] + 1 (for replacement));
        //Delete  (dp[i][j] = dp[i - 1][j] + 1 (for deletion));
        //Insert  (dp[i][j] = dp[i][j - 1] + 1 (for insertion)).
        
        //we now have:
        //dp[i][0] = i;
        //dp[0][j] = j;
        //dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] = word2[j - 1];
        //dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1), otherwise.
        
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++) {
            dp[i][0]=i;
        }
        for(int j=1;j<=n;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
            }
        }
        return dp[m][n];
    }
};