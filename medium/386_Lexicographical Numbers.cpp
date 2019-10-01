class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // DFS & Math

        // Method 1: math
        // time complexity: O(n), space complexity: O(n)
        // 68ms, beats 92.06%
        
        // Main idea:
        // 0. start
        // 1. Attempt to add 0 in the end if not exceed n. Jump to 0
        // 2. If exceed n, / 10
        // 3. Add 1.
        // 4. If trailling zero, remove it. Jump to 0
        
        vector<int> res(n);
        int cur = 1;
        
        for(int i = 0; i < n; ++i) {
            res[i] = cur;
            if(cur * 10 <= n) cur *= 10;
            else {
                if(cur >= n) cur /= 10;
                cur += 1;
                while(cur % 10 == 0) cur /= 10;
            }
        }
        
        return res;
        

        // Method 2: DFS
        // time complexity: O(n), space complexity: O(n) + stack memory
        // 68ms, beats 92.06%
        vector<int> res;
        int limit = min(n, 9) + 1;  // In case if n < 10
        for(int i = 1; i < limit; ++i) {
            dfs(res, n, i);   
        }
        return res;
    }
    
    /* Do dfs on current number, find its next lexicographical number */
    void dfs(vector<int>& res, int n, int cur) {
        res.push_back(cur);
        
        for(int i = 0; i < 10; ++i) {
            if(cur * 10 + i > n) break;
            dfs(res, n, cur * 10 + i);
        }
    }
};