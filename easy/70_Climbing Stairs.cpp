class Solution {
public:
    int climbStairs(int n) {
        // dynamic programming
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        if(n == 1) { return 1; }
        vector<int> ways(n, 0);
        ways[0] = 1; ways[1] = 2;
        for(int i = 2; i < n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n - 1];
        
        // use push_back could avoid edge case like n == 1
        /*
        vector<int> res;
        res.push_back(1);
        res.push_back(2);
        for(int i=2;i<n;i++)
            res.push_back(res[i-1]+res[i-2]);
        return res[n-1];
        */
    }
};