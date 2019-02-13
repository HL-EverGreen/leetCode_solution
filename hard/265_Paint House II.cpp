class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        // DP
        // time complexity: O(nk), space complexity: O(k)
        // 16ms, beats 100%
        // main idea: 
        // 1. maintain the minimal and second minimal value in each round (v1 and v2)
        // 2. if the cheapest plan in last round does not ends with Jth color, choose it
        // 3. if the cheapest plan in last round ends paint with Jth color, choose the second
        // cheapest plan in the last round (to avoid adjancent house having same color)
        // res[i] represents cheapest plan in each round while painting last house with ith color
        
        if(costs.empty() || costs[0].empty()) return 0;
        int n = costs.size(), k = costs[0].size(), v1 = INT_MAX, v2 = INT_MAX;
        vector<int> res(k, 0);

        for(int i = 0; i < n; i++) {
            int old_v1 = (i == 0 ? 0 : v1), old_v2 = (i == 0 ? 0 : v2);
            v1 = INT_MAX, v2 = INT_MAX;
            for(int j = 0; j < k; j++) {
                if(res[j] == old_v1 && old_v1 != old_v2) res[j] = costs[i][j] + old_v2;
                else res[j] = costs[i][j] + old_v1;
                if(res[j] < v1) {
                    v2 = v1;
                    v1 = res[j];
                } else if(res[j] < v2) 
                    v2 = res[j];
            }
        }
        return v1;
    }
};