class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // array & DFS
        // time complexity: O(n^2), space complexity: O(n^2)
        // 8ms, beats 99.81%
        
        vector<vector<int>> res;
        vector<int> sol;
        
        sort(candidates.begin(), candidates.end());
        findCombination(res, sol, candidates, target, 0);
        return res;
    }
    
    // DFS part
    void findCombination(vector<vector<int>>& res, vector<int>& sol, vector<int>& candidates, int target, int start) {
        if(target == 0) {
            res.push_back(sol);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] > target) { return; }
            sol.push_back(candidates[i]);
            findCombination(res, sol, candidates, target - candidates[i], i);
            sol.pop_back();
        }
    }
};