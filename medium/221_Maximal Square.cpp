class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {//dp
        //define dp[i][j] as the maximal size of the square that can be achieved at point (i, j)
        int row=matrix.size(), col=row?matrix[0].size():0,res=0;
        if(col==0) return 0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            dp[i][0]=matrix[i][0]-'0';
            res=max(res,dp[i][0]);
        }
        for(int j=1;j<col;j++) {
            dp[0][j]=matrix[0][j]-'0';
            res=max(res,dp[0][j]);
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]=='1') {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res*res;
    }
};