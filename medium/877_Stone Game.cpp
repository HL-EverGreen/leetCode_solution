class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Method 1:
        // Just return true, because the number of piles is even, so Alex can always pick  all even number of piles or odd numer of piles. So just pick the set with bigger sum.
        // return true;
        
        // Method 2:
        // DP
        // time complexity: O(n^2), space complexity: O(n^2)
        // 8ms, beats 61.65%
        
        // Main idea:
        // dp[i][j] means the biggest number of stones you can get more than opponent picking piles in piles[i] ~ piles[j].
        // You can first pick piles[i] or piles[j].
        // If you pick piles[i], your result will be piles[i] - dp[i + 1][j]
        // If you pick piles[j], your result will be piles[j] - dp[i][j - 1]
        // So we get: dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
        // We start from smaller subarray and then we use that to calculate bigger subarray.
        int size = piles.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));

        /* Set initial value for only one piles to pick situation */
        for(int i = 0; i < size; i++) {
            dp[i][i] = piles[i];
        }
        
        /* Start from short subarray and then go bigger subarray */
        for(int len = 1; len < size; len++) {
            for(int start = 0; start + len < size; start++) {
                dp[start][start + len] = max(piles[start] - dp[start + 1][start + len], piles[start + len] - dp[start][start + len - 1]);
            }
        }
        return dp[0][size - 1] > 0;
    }
};