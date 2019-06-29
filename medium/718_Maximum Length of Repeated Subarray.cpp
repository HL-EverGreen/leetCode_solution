class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // DP
        
        // Method 1
        // matrix DP
        // time complexity: O(mn), space complexity: O(mn)
        // 196ms, beats 49.77%
        // dp[i][j] means that maximum length of subarray that ends in A[i - 1] and B[j - 1]
        /*
        int m = A.size(), n = B.size(), res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res = max(res, dp[i + 1][j + 1] = (A[i] == B[j] ? dp[i][j] + 1 : 0));       // 只和前一轮有关系， 所以可以优化到O(n)
            }
        }
        return res;
        */
        
        // Method 2
        // array DP
        // time complexity: O(mn), space complexity: O(n)
        // 120ms, beats 95.07%
        // dp[j] means that maximum length of subarray that ends at B[j - 1]
        // The key idea to decrease space complexity from O(n^2) to O(n) is to
        // find a way that we can divide the problem into n round, and in each
        // round, we only rely on last round's result.
        // Plus, in each round, we can't let 这轮内的计算结果互相影响，所以这里j要从后往前算
        int m = A.size(), n = B.size();
        vector<int> dp(n + 1, 0);
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                res = max(res, dp[j + 1] = A[i] == B[j] ? 1 + dp[j] : 0);
            }
        }
        return res;
    }
};