class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        // matrix
        // time complexity: O(mn), space complexity: O(1)
        
        // Main idea:
        // Use the row+col to determine which direction to go (up or down)

        // Method 1
        // The diagal's index sum is equal to M + N - 2, so we just iterate through sum and
        // change the direction when sum is odd.
        // 276ms, beats 12%
        
        int M = matrix.size(), N = M == 0 ? N : matrix[0].size();
        if(N == 0) return {};
        vector<int> res;
        int S = M + N - 2;
        for(int cur = 0; cur <= S; ++cur) {
            for(int i = 0, x, y; i <= cur; ++i) {
                if(cur % 2 == 0) {
                    y = i;
                    x = cur - y;
                } else {
                    x = i;
                    y = cur - x;   
                }
                if(x >= M || y >= N) continue;
                res.push_back(matrix[x][y]);
            }
        }
        return res;
        
        
        // Method 2
        // Another loop method, similar to former one, also use row+col to determine whether go up or down
        // 72ms, beats 78.62%
        
        int M = matrix.size(), N = M == 0 ? N : matrix[0].size();
        if(N == 0) return {};
        vector<int> res;
        
        int i = 0, j = 0, num = M * N;
        for(int cnt = 0; cnt < num; ++cnt) {
            res.push_back(matrix[i][j]);
            if((i + j) % 2 == 0) {  // Move upside
                if(j == N - 1) ++i; // Need to first determine col because when we at the topright corner, we need to go down
                else if(i == 0) ++j;
                else {--i, ++j;}
            } else {                // Move downside
                if(i == M - 1) ++j; // Same as above, when we at bottomleft corner, we need to go right
                else if(j == 0) ++i;
                else {++i, --j;}
            }
        }
        return res;
    }
};
