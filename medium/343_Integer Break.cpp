class Solution {
public:
    int integerBreak(int n) {
        // greedy & dp
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Method 1: greedy
        // Use all factor with 2 or 3. (5 < 2 * 3, and so on)
        // So keep reducing 3 until can't go furthur.
        if(n == 2) { return 1; }
        if(n == 3) { return 2; }
        if(n == 4) { return 4; }
        int res = 1;
        while(true) {
            res *= 3;
            n -= 3;
            if(n == 2 || n == 3 || n == 4) {
                return res * n;
            }
        }
        return res;
        
        // Method 2: DP
        // Just try all dp[i] = max(dp[i], j * dp[i - j])
    }
};