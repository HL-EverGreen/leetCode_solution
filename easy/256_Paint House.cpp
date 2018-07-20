class Solution {
public:
    int minCost(vector<vector<int>>& costs) {//Dynamic Programming
        int n=costs.size();
        if(n==0) return 0;
        if(n==1) return min(costs[0][0],min(costs[0][1],costs[0][2]));
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0]=costs[0][0];dp[0][1]=costs[0][1];dp[0][2]=costs[0][2];
        for(int count=1;count<n;count++){
            dp[count][0]=min(dp[count-1][1],dp[count-1][2])+costs[count][0];
            dp[count][1]=min(dp[count-1][0],dp[count-1][2])+costs[count][1];
            dp[count][2]=min(dp[count-1][0],dp[count-1][1])+costs[count][2];
        }
        return min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    }
};