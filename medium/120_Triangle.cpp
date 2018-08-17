class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {//dp
        //bottom to up
        int row=triangle.size();
        if(row==0) return 0;
        vector<int> shortestPath=triangle[row-1];
        for(int index_row=row-2;index_row>=0;index_row--)
            for(int index_col=0;index_col<triangle[index_row].size();index_col++)
                shortestPath[index_col]=min(shortestPath[index_col],shortestPath[index_col+1])+triangle[index_row][index_col];
        return shortestPath[0];
        
        //up to bottom, should find the least element in the last row, time consuming
        /*
        int row=triangle.size(),res=INT_MAX;
        if(row==0) return 0;
        vector<int> shortestPath(row,INT_MAX);
        shortestPath[0]=triangle[0][0];
        for(int index_row=1;index_row<row;index_row++){
            for(int index_col=index_row;index_col>0;index_col--){
                shortestPath[index_col]=min(shortestPath[index_col],shortestPath[index_col-1])+triangle[index_row][index_col];
                if(index_row==row-1) res=min(res,shortestPath[index_col]);
            }
            shortestPath[0]+=triangle[index_row][0];
        }
        res=min(res,shortestPath[0]);
        return res;
        */
    }
};