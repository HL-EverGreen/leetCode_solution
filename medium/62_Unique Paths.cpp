class Solution {
public:
    int uniquePaths(int m, int n) {//math method
        // array & DP
        // time complexity: O(mn), space complexity: O(mn)
        // 0ms, beats 100% 
        
        // general case: dp[i][j] = dp[i + 1][j] + dp[i][j + 1]
        if(m <= 0 || n <= 0) { return 0; }
        int path_num[m][n];
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    path_num[i][j] = 1;
                } else if(i == m - 1) {
                    path_num[i][j] = path_num[i][j + 1];
                } else if(j == n - 1) {
                    path_num[i][j] = path_num[i + 1][j];
                } else{
                    path_num[i][j] = path_num[i + 1][j] + path_num[i][j + 1];
                }
            }
        }
        return path_num[0][0];


        // method 2:
        // mathmatical way
        /*
        if(m<=0 || n<=0) return 0;
        if(m==1 || n==1) return 1;
        double res=1;
        for(int i=0;i<n-1;i++){
            res=res*(m+i);
            res=res/(i+1);
        }
        return int(res);
        */
    }
}; 