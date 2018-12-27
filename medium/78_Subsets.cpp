class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // array & dfs
        // time complexity: O(2^n)
        // 4ms, beats 100.00%
        
        // DFS
        vector<vector<int>> res;
        vector<int> subset;
        generateAllSubsets(res, subset, nums, 0);
        return res;
    }
    
    // DFS part
    void generateAllSubsets(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int start) {
        res.push_back(subset);
        for(int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            generateAllSubsets(res, subset, nums, i + 1);   // notice: not $start + 1$
            subset.pop_back();
        }
    }
};