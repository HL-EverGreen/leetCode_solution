class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // DP
        // time complexity: O(n), space complexity: space complexity: O(n)
        // 8ms, beats 82.76%
        
        // dp[i] means the minimum cost needed to jump to block i.
        // So res is dp[size]
        int size = cost.size();
        vector<int> dp(size + 1);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= size; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }
};