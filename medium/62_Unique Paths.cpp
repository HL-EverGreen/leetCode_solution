class Solution {
public:
    int uniquePaths(int m, int n) {//math method
        if(m<=0 || n<=0) return 0;
        if(m==1 || n==1) return 1;
        double res=1;
        for(int i=0;i<n-1;i++){
            res=res*(m+i);
            res=res/(i+1);
        }
        return int(res);
        
        //or generally, recursive
        /*
         vector<vector<int>> cache(m, vector<int>(n, 0));
        
        cache[m-1][n-1] = 1;
        for(int i=m-1; i>=0; --i) {
            for(int j=n-1; j>=0; --j) {
                if(i+1 < m)
                    cache[i][j] += cache[i+1][j];
                if(j+1 < n)
                    cache[i][j] += cache[i][j+1];
            }
        }
        
        return cache[0][0];
        */
    }
};