class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp & dfs with memo
        // time complexity: O(mn), space complexity: O(m), m is the amount, n is the number of coins
        // 8ms, beats 76.22%
        
        // Main idea:
        // DFS + memo is a good solution (should consider to avoid duplicate)
        // DP is more direct. Here, dp[i] presends number of plans to change for money `amount`
        // In order to avoid duplicate, we iterate through the coins first,
        // so in each round, we can only add this coin `c` into plan.
        // And try this coin `c` for each amount >= `c`
        
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(auto& c : coins) {  // Loop through coin first to avoid dups
            for(int i = c; i <= amount; ++i) {
                dp[i] += dp[i - c]; // Apply coin c into current plan
            }
        }
        return dp[amount];
    }
};