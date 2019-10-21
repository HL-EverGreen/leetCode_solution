class Solution {
public:
    int numberOfPatterns(int m, int n) {
        // DFS & DP (DP see below)
        // 36ms,beats 54.55%
        
        // main idea:
        // Use skip to record skip number, and straight forward dfs.
        // The next number can only be chosen when it is not used, and no number is skipped
        // or the skipped number has been used.
        // Since 1,3,7,9 and 2,4,6,8 are symmetric, we only need to compute one and multiply by 4
        
        // Create the skip relation
        vector<vector<int>> skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        
        // Loop for different start point
        vector<bool> visited(10, false);
        int res = 0;
        for(int i = m; i <= n; ++i) {
            res += dfs(skip, visited, 1, i - 1) * 4;
            res += dfs(skip, visited, 2, i - 1) * 4;
            res += dfs(skip, visited, 5, i - 1);
        }
        return res;
    }
    
    // Do dfs starting with number `cur`, with `remain` steps remain
    int dfs(vector<vector<int>>& skip, vector<bool>& visited, int cur, int remain) {
        if(remain <= 0) return 1;
        int ret = 0;
        visited[cur] = true;
        for(int i = 1; i <= 9; ++i) {
            if(!visited[i] && (skip[cur][i] == 0 || visited[skip[cur][i]])) {   // Skip nothing or skipped used value
                ret += dfs(skip, visited, i, remain - 1);
            }
        }
        visited[cur] = false;
        return ret;
    }
};

// DP solution
/*
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> dp((1<<9),vector<int>(9,0));
        vector<int> ret(9,0);
        for(int i=0;i<9;++i) dp[1<<i][i]=1;
        for(int i=1;i<(1<<9);++i) {
            int count=0;
            int tmp=i;
            while(tmp) {
                count++;
                tmp&=(tmp-1);
            }
            if(count>n) continue;
            for(int j=0;j<9;++j) {
                ret[count-1]+=dp[i][j];
                if(i&(1<<j)) {
                    int x=j/3;
                    int y=j%3;
                    for(int k=0;k<9;++k) {
                        if(!(i&(1<<k))) {
                            int x1=k/3;
                            int y1=k%3;
                            if(((x==x1&&abs(y-y1)==2)||(y==y1&&abs(x-x1)==2)||(abs(x-x1)==2&&abs(y-y1)==2))&&!(i&(1<<(3*(x+x1)/2+(y+y1)/2)))) continue;                          
                            dp[i+(1<<k)][k]+=dp[i][j];
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=m-1;i<n;++i) ans+=ret[i];
        return ans;
    }
};
*/