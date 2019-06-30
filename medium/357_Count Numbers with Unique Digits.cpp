class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // DP
        // time complexity: O(n^2), space complexity: O(n)
        // 0ms, beats 100%
        
        // dp[i] means number of unique numbers within 10^i.
        // dp[i] = dp[i - 1] + number of unique numbers within [10^(i-1), 10^i)
        // The latter is equal to 9 * 9 * 8 * 7... (first digit can't be 0)
        
        vector<long> dp(n + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            dp[i] = 9;
            for(int cnt = 1, factor = 9; cnt < i; cnt++, factor--) {
                dp[i] *= factor;
            }
            dp[i] += dp[i - 1];
        }
        return dp[n];
    }
};