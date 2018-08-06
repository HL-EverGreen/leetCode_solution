class Solution {
public:
    int numIslands(vector<vector<char>>& grid) { //dfs
        int res=0;
        if(grid.size()==0 || grid[0].size()==0) return res;
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1') { //when find 1, res++, and set all 1 which belongs to the same island to 0 through DFS
                    res++;
                    dfs(grid,i,j,row,col);
                }
            }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col){
        grid[i][j]='0';
        if(i>0 && grid[i-1][j]=='1')
            dfs(grid,i-1,j,row,col);
        if(i<row-1 && grid[i+1][j]=='1')
            dfs(grid,i+1,j,row,col);
        if(j>0 && grid[i][j-1]=='1')
            dfs(grid,i,j-1,row,col);
        if(j<col-1 && grid[i][j+1]=='1')
            dfs(grid,i,j+1,row,col);
    }
};