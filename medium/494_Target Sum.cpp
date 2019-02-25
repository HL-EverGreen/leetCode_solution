class Solution {
public:
    // method 1 : DFS + memorization
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
    
    // method 2: DP
    // time complexity: O(ns)
    // 152ms, beats 59.53%
    
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
};
