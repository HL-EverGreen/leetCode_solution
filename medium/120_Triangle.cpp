class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // array
        // time complexity: O(n^2), space complexity: O(n)
        // 4ms, beats 99.39%
        
        // method 1, do it in place
        // update in place, from down to top, line by line
        // or we can use new O(n) space and update values in that new O(n) space
        int row = triangle.size(), min_sum = 0;
        for(int i = row - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // method 2, use new O(n) space
        //bottom to up
        /*
        int row=triangle.size();
        if(row==0) return 0;
        vector<int> shortestPath=triangle[row-1];
        for(int index_row=row-2;index_row>=0;index_row--)
            for(int index_col=0;index_col<triangle[index_row].size();index_col++)
                shortestPath[index_col]=min(shortestPath[index_col],shortestPath[index_col+1])+triangle[index_row][index_col];
        return shortestPath[0];
        */
        
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