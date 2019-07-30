class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // bucket sort
        // time complexity: O(mn), space complexity: O(mn)
        // 64ms, beats 94.11%
        
        // Main idea:
        // Sort dis into bucket, and iter from short dis to large dis
        vector<vector<pair<int, int>>> bucket(1999, vector<pair<int, int>>());          // Max dis is 1999
        int n = workers.size(), m = bikes.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                bucket[dis].push_back({i, j});                                          // Construct bucket
            }
        }
        
        vector<int> res(n, -1);
        vector<bool> usedBike(m, false);
        for(int dis = 1; dis <= 1998; dis++) {                              // Iter according to dis
            auto tmp = bucket[dis];
            int size = tmp.size();
            for(int i = 0; i < size; i++) {
                if(res[tmp[i].first] == -1 && !usedBike[tmp[i].second]) {   // Worker is not assigned yet and bike is available
                    res[tmp[i].first] = tmp[i].second;
                    usedBike[tmp[i].second] = true;
                }
            }
        }
        return res;
    }
};