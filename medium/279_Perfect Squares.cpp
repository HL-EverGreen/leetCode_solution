class Solution {
public:
    int numSquares(int n) {//dp
        //use static vector to save running time(LeetCode doesn't clear static variables)
        if(n<=0) return 0;
        static vector<int> dp({0});
        while(dp.size()<=n){
            int i=dp.size();
            int cur=INT_MAX;
            for(int j=1;j*j<=i;j++)
                cur=min(cur,dp[i-j*j]+1);
            dp.push_back(cur);
        }
        return dp[n];
        
        //general vector
        /*
        if(n<=0) return 0;
        vector<int> dp({0});
        for(int i=1;i<=n;i++){
            int cur=INT_MAX;
            for(int j=1;j*j<=i;j++)
                cur=min(cur,dp[i-j*j]+1);
            dp.push_back(cur);
        }
        return dp.back();
        */
    }
};