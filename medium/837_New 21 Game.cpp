class Solution {
public:
    double new21Game(int N, int K, int W) {
        // DP
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 82.26%
        
        // Main idea:
        // dp[i] means the probs of getting in i.
        // Like climbing stairs, i can only get from [i - W, i - 1]
        // So calculate sum of probs in [i - W, i - 1]
        // For dp[i], dp[i] = lastWSum / W;
        // And keep update last W sum. (don't add new elements >= K)
        
        if(K == 0) return 1;
        vector<double> dp(N + 1);
        double pastWSum = 1, res = 0;
        dp[0] = 1;                      // Start from 0, so probs[0] = 1
        
        for(int i = 1; i <= N; ++i) {
            dp[i] = pastWSum / W;
            if(i >= K) res += dp[i];
            else pastWSum += dp[i];     // Only add probs of elements < K, since that would led to one more draw
            if(i >= W) pastWSum -= dp[i - W];   // Remove out of W window element's prob
        }
        return res;
    }
};