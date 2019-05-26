class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // DFS
        // 72ms, beats 98.58%
        
        // Main idea:
        // Since no cycling exists in the given format, just use DFS directly.
        // When cur index == N - 1, find path, and push current path into final result
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        findAllPaths(graph, res, path, 0);
        return res;
    }
    
    void findAllPaths(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int cur) {
        if(cur == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        
        for(auto next : graph[cur]) {
            path.push_back(next);
            findAllPaths(graph, res, path, next);
            path.pop_back();
        }
    }
};