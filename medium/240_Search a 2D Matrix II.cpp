class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {//matrix
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int i=0,j=matrix[0].size()-1,m=matrix.size();
        while(i<m && j>=0){                    //instead of while(i<matrix.size() && j>=0) to save running time
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};