class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        if(grid.size()==0||grid[0].size()==0)
            return 0;
        vector<vector<int>> res(grid.size(),vector<int>(grid[0].size(),0));
        res[grid.size()-1][grid[0].size()-1]=grid[grid.size()-1][grid[0].size()-1];
        dp(grid,res,grid.size(),grid[0].size());
        return res[0][0];
    }
    
    void dp(vector<vector<int>> grid, vector<vector<int>>& res, int row, int col){
        for(int n=col-1;n>=0;n--){
            for(int m=row-1;m>=0;m--){
                if(n==col-1 && m==row-1)
                    continue;
                else if(n==col-1)
                    res[m][n]=res[m+1][n]+grid[m][n];
                else if(m==row-1)
                    res[m][n]=res[m][n+1]+grid[m][n];
                else
                    res[m][n]=min(res[m+1][n],res[m][n+1])+grid[m][n];
            }
        }
    }
};