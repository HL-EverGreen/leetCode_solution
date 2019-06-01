class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        // Matrix
        // time complexity: O(mn), space complexity: O(1)
        // 56ms, beats 94.65%
        
        // Main idea:
        // Use x, y to present goin direction.
        // And the move rule is : 1, 1, 2, 2, 3, 3, ...
        // So we just follow the move rule.
        vector<vector<int>> res{{r0, c0}};
        int x = 0, y = 1, tmp;
        
        for(int n = 0; res.size() < R * C; n++) {
            for(int i = 0; i < n / 2 + 1; i++) {
                r0 += x, c0 += y;
                if(r0 < 0 || r0 >= R || c0 < 0 || c0 >= C) { continue; }
                res.push_back({r0, c0});
            }
            tmp = x, x = y, y = -tmp;
        }
        return res;
    }
};