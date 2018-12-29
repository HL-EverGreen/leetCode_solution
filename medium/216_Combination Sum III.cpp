class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        // array & DFS
        // time complexity: O(n^3), space complexity: O(n)
        // 0ms, beats 100%
        
        vector<vector<int>> res;
        vector<int> group;
        findCombination(res, group, 1, n, k);
        return res;
    }
    
    // DFS part
    void findCombination(vector<vector<int>>& res, vector<int>& group, int cur, int remain, int num) {
        if(group.size() == num && remain == 0) {
            res.push_back(group);
            return;
        }
        for(int i = cur; i <= 9; i++) {
            if(remain < i) { return; }
            group.push_back(i);
            findCombination(res, group, i + 1, remain - i, num);
            group.pop_back();
        }
    }
};