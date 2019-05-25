class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        // Matrix
        // time complexity: O(n^2), space complexity: O(1)
        // 12ms, beats 94.99%
        
        /* Reverse */
        for(auto &row : A) {
            reverse(row.begin(), row.end());
        }
        
        /* Toggle */
        for(auto &row : A) {
            for(auto &elem : row) {
                elem ^= 1;
            }
        }
        return A;
        
        
        // Only reset value for those equal pairs.
        // Because the result of swap + toggle unequal pairs is the same.
        // Notice: j * 2 < n can just 都取到中间无论奇偶
        /*
        int n = A.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j * 2 < n; j++) {
                if(A[i][j] == A[i][n - j - 1]) {
                    A[i][j] = A[i][n - j - 1] ^= 1;
                }
            }
        }
        return A;
        /*
    }
};