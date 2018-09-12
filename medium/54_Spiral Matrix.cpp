class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { //matrix
        int row_end=matrix.size(), col_end=row_end?matrix[0].size():0, row_start=0, col_start=0;
        if(col_end==0) return vector<int>();
        int i=0,j=0;
        vector<int> res;
        while(row_end>row_start && col_end>col_start){
            for(int j=col_start;j<col_end;j++) res.push_back(matrix[row_start][j]);
            if(++row_start==row_end) break;
            for(int i=row_start;i<row_end;i++) res.push_back(matrix[i][col_end-1]);
            if(--col_end==col_start) break;
            for(int j=col_end-1;j>=col_start;j--) res.push_back(matrix[row_end-1][j]);
            if(--row_end==row_start) break;
            for(int i=row_end-1;i>=row_start;i--) res.push_back(matrix[i][col_start]);
            if(++col_start==col_end) break;
        }
        return res;
    }
};