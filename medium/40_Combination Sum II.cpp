class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // array & DFS
        // time complexity: O(2^n), space complexity: O(2^n)
        // 4ms, beats 100%
        
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
            if(i == start || candidates[i] > candidates[i - 1]) {                       // ensure no duplicated solutions
                sol.push_back(candidates[i]);
                findCombination(res, sol, candidates, target - candidates[i], i + 1);
                sol.pop_back();
            }
        }
    }
};