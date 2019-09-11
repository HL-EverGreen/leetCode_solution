class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // array & stack & DP

        // method 1
        // stack
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // Main idea:
        // We use stack to store value, and we guarantee that this stack is a decreasing stack.
        // When current value is larger than the top value, the top value finds its all candidates (its left greater one and right greater one)
        // So we can choose the smaller one to remove the top value.
        // After iteration, there remains a decreasing stack, and the values in the stack only has left candidate. We calculate using left cand.
        
        // Lee215's explaination:
        // The problem is same as:
        // Given an array A, choose two neighbors in the array a and b,
        // we can remove the smaller one min(a,b) and the cost is a * b.
        // What is the minimum cost to remove the whole array until only one left?

        // To remove a number a, it needs a cost a * b, where b >= a.
        // So a has to be removed by a bigger number. We want minimize this cost, so we need to minimize b.
        // b has two candidates, the first bigger number on the left, and the first bigger number on the right.
        // The cost to remove a is a * min(left, right).
        
        int res = 0, n = arr.size();
        vector<int> stack = {INT_MAX};
        for(int a : arr) {
            while(stack.back() <= a) {      // The top value finds its left and right candidates, use the smaller one to remove top value.
                int mid = stack.back(); stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        
        for(int i = 1; i < stack.size() - 1; ++i) { // Remove remain value, which only has left candidates.
            res += stack[i] * stack[i + 1];
        }
        
        return res;
        
        
        // method 2
        // DP solution
        // time complexity: O(n^3), space complexity: O(n^2)
        // 32ms, beats 12.8%
        
        // Main idea:
        // Kinda brute force, try all combination
        // dp[i][j] presents the result for tree with leaf nodes from arr[i] ~ arr[j].
        // So, for k in [i, j-1]: dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + max(A[i~k]) * max(A[k+1][j]))
        // Special case: 
        //    1) dp[i][i] = 0, since no parent node
        //    2) dp[i][i + 1] = arr[i] * arr[i + 1]
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, unordered_map<int, int>> max_val;
        
        for(int i = 0; i < n; ++i) {
            max_val[i][i] = arr[i];
        }
        
        for(int len = 1; len < n; ++len) {
            for(int start = 0; start + len < n; ++start) {
                int end = start + len;
                dp[start][end] = INT_MAX;
                for(int k = start; k < end; ++k) {
                    dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + max_val[start][k] * max_val[k + 1][end]);
                }  
                max_val[start][end] = max(max_val[start][start], max_val[start + 1][end]);  
            }
        }
        return dp[0][n - 1];
    }
};