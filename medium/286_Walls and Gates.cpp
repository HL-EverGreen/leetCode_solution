class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[0].size();j++){
                if(rooms[i][j]==0)
                    dfs(i,j,0,rooms);
            }
        }
    }
    
    void dfs(int index_row,int index_col,int dis,vector<vector<int>>& rooms){//bfs is faster
        if(index_row>=0 && index_row<rooms.size() && index_col>=0 && index_col<rooms[0].size() && dis<=rooms[index_row][index_col]){
            rooms[index_row][index_col]=dis;
            dfs(index_row+1,index_col,dis+1,rooms);
            dfs(index_row-1,index_col,dis+1,rooms);
            dfs(index_row,index_col+1,dis+1,rooms);
            dfs(index_row,index_col-1,dis+1,rooms);
        }
    }
};