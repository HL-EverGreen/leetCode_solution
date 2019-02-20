class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // dp
        // time complexity: O(n^3), space complexity: O(n^2)
        // 20ms, beats 99%
        
        int N = nums.size();
        if(N == 0) return 0;
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        // rangeValues[i][j] is the maximum # of coins that can be obtained
        // by popping balloons only in the range [i,j]
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
        
        for(int len = 1; len <= N; len++) {
            for(int start = 1; start + len - 1 <= N; start++) {
                // calculate the max # of coins that can be obtained by
                // popping balloons only in the range [start,end].
                // consider all possible choices of final balloon to pop
                int end = start + len - 1, bestCoins = 0;
                for(int fin = start; fin <= end; fin++) {
                    int coin = dp[start][fin - 1] + dp[fin + 1][end];      // coins from popping subranges
                    coin += nums[start - 1] * nums[end + 1] * nums[fin];   // coins from final pop
                    bestCoins = max(bestCoins, coin);
                }
                dp[start][end] = bestCoins;
            }
        }
        return dp[1][N];
    }
};