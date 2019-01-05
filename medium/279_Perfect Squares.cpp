class Solution {
public:
    int numSquares(int n) {//dp
        // dynamic programming
        // time complexity: O(n^2), space complexity: O(n)
        // 8ms, beats 89.3%
        
        // use static vector
        // cur = min(cur, res[i - j * j] + 1);
        if(n <= 0) { return 0; }
        static vector<int> res({0});
        while(res.size() <= n) {
            int cur = INT_MAX, i = res.size();
            for(int j = 1; j * j <= i; j++) {
                cur = min(cur, res[i - j * j] + 1);
            }
            res.push_back(cur);
        }
        return res[n];
        
        
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