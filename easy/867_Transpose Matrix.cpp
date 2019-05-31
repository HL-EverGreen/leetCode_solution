class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        // matrix
        // time complexity: O(mn), space complexity: O(1)
        // 28ms, beats 89.58%
        
        // Main idea:
        // Straight forward swapping
        int row = A.size(), col = A[0].size();
        vector<vector<int>> res(col, vector<int>(row));
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};