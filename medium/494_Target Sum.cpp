class Solution {
public:
    // method 1: DP
    int findTargetSumWays(vector<int>& nums, int S) {
        // DP
        // time complexity: O(nS), space complexity: O(S)
        // 4ms, beats 97.56%
        
        // Main idea:
        // Since, sum(P) - sum(N) = target
        // So, sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
        // So, 2 * sum(P) = target + sum(nums)
        // So the original problem has been converted to a subset sum problem as follows:
        // Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < S || (S + sum) & 1 ? 0 : subsetSum(nums, (S + sum) >> 1);          // Simply return if sum + S is odd (which can't be divided by 2)
    }
    
    int subsetSum(vector<int>& nums, int s) {
        int dp[s + 1] = {0};
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }

    // method 2: DP
    // my dp version, need two dp array
    // 40ms
    /*
    int findTargetSumWays(vector<int>& nums, int S) {
        int dp1[2001] = {0}, dp2[2001] = {0}, size = nums.size();
        if(S < -1000 || S > 1000) { return 0; }
        
        dp1[1000 + nums[0]] += 1;
        dp1[1000 - nums[0]] += 1;
        for(int i = 1; i < size; i++) {
            int cur = nums[i];
            for(int j = 0; j < 2001; j++) {
                dp2[j] = (j + cur < 2001 ? dp1[j + cur] : 0) + (j - cur >= 0 ? dp1[j - cur] : 0); 
            }
            swap(dp1, dp2);
        }
        return dp1[1000 + S];
    }
    */
    
    // method 3: DP
    // time complexity: O(ns)
    // 152ms, beats 59.53%
    /*
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        vector<unordered_map<long, int>> dp(size + 1);
        dp[0][0] = 1;
        for(int i = 0; i < size; i++) {
            for(auto& p : dp[i]) {
                dp[i + 1][p.first + nums[i]] += p.second;
                dp[i + 1][p.first - nums[i]] += p.second;
            }
        }
        return dp[size][S];
    }
    */

    // method 4 : DFS + memorization
    // time complexity: O(ns)
    // 240ms, beats 50.15%
    /*
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<long, int>> m(nums.size());
        return dfs(m, nums, S, 0);
    }
    
    int dfs(vector<unordered_map<long, int>>& m, vector<int>& nums, long S, int idx) {
        if(idx == nums.size()) return S == 0;
        if(m[idx].find(S) != m[idx].end()) return m[idx][S];
        int t1 = dfs(m, nums, S - nums[idx], idx + 1);
        int t2 = dfs(m, nums, S + nums[idx], idx + 1);
        m[idx][S] = t1 + t2;
        return m[idx][S];
    }
    */
};
