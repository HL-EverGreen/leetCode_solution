class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        // DP
        // time complexity: O(nk), space complexity: O(n)
        // 12ms, beats 95.91%
        
        // Main idea:
        // dp[i] presents maximum sum when only consider A[0] ~ A[i - 1]
        // For each index i, check subarray ends with A[i] with length k in 1<=k<=K.
        // Use curMax to find max number in current subarray, and current subarray's value is equal to curMax * k
        // Then compare dp[i - k] (or 0) + curMax * k with dp[i]
        int size = A.size();
        vector<int> dp(size);
        
        for(int i = 0; i < size; i++) {
            int curMax = 0;
            for(int k = 1; k <= K && i - k + 1 >= 0; k++) {
                curMax = max(curMax, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
            }
        }
        return dp[size - 1];
    }
};