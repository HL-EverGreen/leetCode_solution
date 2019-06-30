class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        // DP
        // time complexity: O(n^2), space complexity: O(n)
        // 4ms, beats 100%
        
        // Main idea:
        // dp[i] present minimum height needed to put first i books.
        // For ith book, if put in new shelf, dp[i] = dp[i - 1] + h.
        // Or put in the last shelf, so try to put with former books until can't
        // put in one shelf, in this case, dp[i] = min(dp[i], dp[j - 1] + h), where
        // h is the maximum height in current shelf.

        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            int w = books[i - 1][0], h = books[i - 1][1];
            dp[i] = dp[i - 1] + h;                              // Put in new shelf
            for(int j = i - 1; j > 0; j--) {                    // Try with former book
                w += books[j - 1][0];
                if(w > shelf_width) { break; }
                h = max(h, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + h);
            }
        }
        return dp[n];
    }
};