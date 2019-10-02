class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        // DP
        // time complexity: O(n^3), space complexity: O(n^2)
        // 0ms, beats 100%
        
        // Main idea:
        // Similar to merge binary tree.
        // First loop length, and adjust start index. Then select min cost for all possible middle position.
        
        int N = stones.size();
        if((N - 1) % (K - 1)) return -1;    // Can't merge into one stone
        
        vector<int> prefix(N + 1, 0);
        for(int i = 0; i < N; ++i) prefix[i + 1] = prefix[i] + stones[i];
 
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int len = K - 1; len < N; ++len) {
            for(int start = 0; start + len < N; ++start) {
                int end = start + len;
                dp[start][end] = INT_MAX;
                for(int mid = start; mid < end; mid += K - 1) { // We can merge K + (K - 1) * steps into one pile.
                    dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end]);
                }
                if(len % (K - 1) == 0) dp[start][end] += prefix[end + 1] - prefix[start];   // Can merge into one
            }
        }
        return dp[0][N - 1];
    }
};