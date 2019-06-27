class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // DP
        // time complexity: O(1), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // dp[i] means minimum cost to travel containing days <= i, so res is dp[365]
        // Convert `days` into set so we can determine whether day i is in `days`.
        // If day i isn't in `days`, dp[i] = dp[i - 1]
        // If day i in `days`, compare dp[i - 1/7/30] + costs[0/1/2]
        unordered_set<int> d(days.begin(), days.end());
        int dp[366] = {0};
        for(int i = 1; i < 366; i++) {
            if(d.find(i) == d.end()) {                      // i not in travel days
                dp[i] = dp[i - 1];
            } else {                                        // i in travel days
                dp[i] = min({dp[i - 1] + costs[0],
                             dp[max(i - 7, 0)] + costs[1],
                             dp[max(i - 30, 0)] + costs[2]});
            }
        }
        return dp[365];
    }
};
