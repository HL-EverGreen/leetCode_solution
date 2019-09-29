class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // dfs
        // time complexity: O(2^n), space complexity: O(2^n) + stack memory
        // 192ms, beats 93.22%
        
        // Main idea:
        // Straight forward DFS.
        // Note: use hashset in each DFS loop to avoid adding duplicate result.
        
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }
    
    /* Do DFS on nums and find all possible combinations */
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int start) {
        if(cur.size() >= 2) res.push_back(cur);
        
        unordered_set<int> seen;
        for(int i = start; i < nums.size(); ++i) {
            int num = nums[i];
            if((cur.empty() || num >= cur.back()) && !seen.count(num)) {    // Avoid use same number as the start
                seen.insert(num);
                cur.push_back(num);
                dfs(nums, res, cur, i + 1);
                cur.pop_back();
            }
        }
    }
};