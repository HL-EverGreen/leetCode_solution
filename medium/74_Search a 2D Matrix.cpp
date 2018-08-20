class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {//matrix
        int row=matrix.size(), col=row?matrix[0].size():0;
        if(col==0) return false;
        for(int i=0;i<row;i++){
            if(matrix[i][col-1]<target) continue;
            for(int j=col-1;j>=0;j--)
                if(matrix[i][j]==target) return true;
        }
        return false;
    }
};