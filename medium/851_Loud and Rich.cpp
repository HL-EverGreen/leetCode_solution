class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // DFS
        // time complexity: O(n), n is the number of people, space complexity: O(mn)
        // 108ms, beats 77.84%
        
        // Main idea:
        // Use map to record topological relation.
        // For each node, do DFS, and memorize with res[i].

        int n = quiet.size();
        unordered_map<int, vector<int>> m;
        vector<int> res(n, -1);
        
        /* Transform relation represent */
        for(auto rich : richer) {
            m[rich[1]].push_back(rich[0]);
        }
        for(int i = 0; i < n; i++) {
            dfs(m, res, quiet, i);
        }
        return res;
    }
    
    int dfs(unordered_map<int, vector<int>>& m, vector<int>& res, vector<int>& q, int cur) {
        if(res[cur] != -1) { return res[cur]; }         // If already computed.
        res[cur] = cur;                                 // Default value.
        for(auto next : m[cur]) {
            int tmp = dfs(m, res, q, next);             // Least queit people in subtree
            if(q[tmp] < q[res[cur]]) {
                res[cur] = tmp;
            }
        }
        return res[cur];
    }
};