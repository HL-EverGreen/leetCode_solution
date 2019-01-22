class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // matrix & greedy
        // time complexity: O(n^2), space complexity: O(1)
        // 0ms, beats 100%
        
        // Flip all row[i][0] to 1, then flip by col
        int row = A.size(), col = A[0].size();
        for(int i = 0; i < row; i++) {
            if(A[i][0] == 0) {
                for(int j = 0; j < col; j++) {
                    A[i][j] ^= 1; 
                }    
            }
        }
        int res = row * pow(2, col - 1);
        for(int j = 1; j < col; j++) {
            int cnt = 0;
            for(int i = 0; i < row; i++) cnt += A[i][j];
            res += (cnt > row / 2 ? cnt * pow(2, col - j - 1) : (row - cnt) * pow(2, col - j - 1));
        }
        return res;
    }
};