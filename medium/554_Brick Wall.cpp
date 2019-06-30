class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // hash table
        // time complexity: O(mn), space complexity: O(n), n is number of bricks per row
        // 40ms, beats 97.27%
        
        // Main idea:
        // This problem is equal to find a point where has the most brick edges.
        // So use unordered_map to record each edge's position, and select the most frequent point.
        unordered_map<int, int> m;
        for(auto row : wall) {
            int sum = 0;
            for(int i = 0; i < row.size() - 1; i++) {       // Notice: not add the last edge (which is the side of wall)
                m[sum += row[i]]++;
            }
        }
        
        int res = 0;
        for(auto elem : m) {
            res = max(res, elem.second);
        }
        return wall.size() - res;
    }
};