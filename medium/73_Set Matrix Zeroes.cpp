class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {//matrix
        
        int col0=1,rows=matrix.size(),cols=rows?matrix[0].size():0; //Because the state of row0 and the state of column0 would
                                                                    //occupy the same cell, I let it be the state of row0,
                                                                    //and use another variable "col0" for column0
        
        for(int i=0;i<rows;i++){        //store every coords of element 0 in first column and row
            if(matrix[i][0]==0) col0=0;
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        
        for(int i=rows-1;i>=0;i--){     //if detect the 0 sign, set element to 0
            for(int j=cols-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(col0==0) matrix[i][0]=0;
        }
    }
};