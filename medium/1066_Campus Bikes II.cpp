struct hash_pair {
    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // DFS + memo & DP
        // 12ms, beats 71.37%
        
        // Main idea:
        // Use bit mask (as int here since max has 10 bikes.) to represent whether
        // bike i has been assigned.
        // Use memo to track if {current worker id, bikes status} has been calculated

        // *For DP, the same as this DFS + memo, but in iteration style.
        // DP: dp[idx][bikes_bit] means minimum dis when finished assigning worker `idx` with bike status in `bikes_bit`
        // The result is min{dp[N][~]}
        // For calculating each dp[idx][bikes_bit], check all dp[idx - 1][~], to conduct 
        // dp[idx][bike_bis] = min(self, dp[idx - 1][~] + dis(idx, ~))

        int n = workers.size();
        int bikeUsed = 0;   // bit mask
        unordered_map<pair<int, int>, int, hash_pair> memo;
        return dfs(workers, bikes, memo, bikeUsed, 0);
    }
    
    /*  DFS with memo to find minimum dis with given starting worker id and bikes status */
    int dfs(vector<vector<int>>& workers, vector<vector<int>>& bikes,
            unordered_map<pair<int, int>, int, hash_pair>& memo, int& bikeUsed, int idx) {
        if(idx >= workers.size()) return 0;
        if(memo.count({idx, bikeUsed})) return memo[{idx, bikeUsed}];   // In memo
        
        int res = INT_MAX;
        for(int i = 0; i < bikes.size(); ++i) {
            if(bikeUsed & (1 << i)) continue;         // Bike has already assigned
            bikeUsed |= (1 << i);
            res = min(res, computeDis(workers[idx], bikes[i])   // Attempt to assign unused bike to current worker and enter sub branch
                      + dfs(workers, bikes, memo, bikeUsed, idx + 1));
            bikeUsed &= ~(1 << i);
        }
        
        return memo[{idx, bikeUsed}] = res;
    }
    
    /* Compute distance between two points */
    int computeDis(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};