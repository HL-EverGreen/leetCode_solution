class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { //dp
        //dp[i][j] presents block(i,j)'s number of unique paths, here I change obstacleGrid directly instead of defining new dp[][]
        //the main idea is that dp[i][j]=dp[i+1][j]+dp[i][j+1]; if dp[i+1][j] or dp[i][j+1] has obstacle, just use 0 when add up
        int row=obstacleGrid.size(), col=row?obstacleGrid[0].size():0;
        if(col==0) return 0;
        for(int id_row=row-1;id_row>=0;id_row--){
            for(int id_col=col-1;id_col>=0;id_col--){
                if(obstacleGrid[id_row][id_col]==1){
                    if((id_row==row-1 && id_col==col-1) || (id_row==0 && id_col==0)) return 0; //obstacle located in start point or end point
                    obstacleGrid[id_row][id_col]=-1; //use -1 to present obstacle instead of 1
                    continue;
                }
                if(id_col==col-1 && id_row==row-1) obstacleGrid[id_row][id_col]=1;
                else if(id_col==col-1) obstacleGrid[id_row][id_col]+=obstacleGrid[id_row+1][id_col]==-1?0:obstacleGrid[id_row+1][id_col];
                else if(id_row==row-1) obstacleGrid[id_row][id_col]+=obstacleGrid[id_row][id_col+1]==-1?0:obstacleGrid[id_row][id_col+1];
                else obstacleGrid[id_row][id_col]+=(obstacleGrid[id_row][id_col+1]==-1?0:obstacleGrid[id_row][id_col+1])+(obstacleGrid[id_row+1][id_col]==-1?0:obstacleGrid[id_row+1][id_col]);
            }
        }
        return obstacleGrid[0][0];
    }
};