class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        // DP
        // time complexity: O(nk), space complexity: O(k)
        // 8ms, beats 100%
        // main idea: 
        // 1. maintain the minimal and second minimal value in each round (v1 and v2)
        // 2. if the cheapest plan in last round does not ends with Jth color, choose it
        // 3. if the cheapest plan in last round ends paint with Jth color, choose the second
        // cheapest plan in the last round (to avoid adjancent house having same color)
        // res[i] represents cheapest plan in each round while painting last house with ith color
        
        if(costs.empty() || costs[0].empty()) return 0;
        int N = costs.size(), K = costs[0].size();
        int old_v1, old_v2, v1 = 0, v2 = 0;
        vector<int> total(K, 0);
        
        for(int i = 0; i < N; ++i) {    // Iterate through N house
            old_v1 = v1; old_v2 = v2;
            v1 = INT_MAX; v2 = INT_MAX;
            for(int j = 0; j < K; ++j) { // Calculate each plan if paint house i with color j
                if(old_v1 == total[j] && old_v1 != old_v2) total[j] = old_v2 + costs[i][j]; // If last cheapest plan is also painting with color j
                else total[j] = old_v1 + costs[i][j];
                if(total[j] < v1) {
                    v2 = v1;
                    v1 = total[j];
                } else if(total[j] < v2) v2 = total[j];
            }
        }
        return v1;
    }
};