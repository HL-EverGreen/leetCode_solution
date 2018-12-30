class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // array
        // time complexity: O(n^2), space complexity: O(1)
        // 0ms, beats 100%

        // method 1:
        // swap diagonally (m[i][j] and m[j][i]), then reverse each row
        int row = matrix.size(), col = (row == 0 ? 0 : matrix[0].size());
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < row; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // method 2:
        // mathmatical way
        /*
        int r = matrix.size();
        if(!r)
            return;
        int c = matrix[0].size();
        
        for( int i = 0; i < r/2; i++)
        {
            for( int j = i; j < r-i-1;j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[r-1-j][i];
                matrix[r-1-j][i] = matrix[r-1-i][c-1-j];
                matrix[r-1-i][c-1-j] = matrix[j][c-1-i];
                matrix[j][c-i-1] = temp;
            }
        }
        */
    }
};