class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // BFS & DFS
        // time complexity: O(n), space complexity: O(n)
        // 168ms, beats 87.07%
        
        // topological dep
        unordered_map<int, vector<int>> child;
        int n = pid.size();
        for(int i = 0; i < n; i++) {
            child[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> res;
        queue<int> process;
        process.push(kill);
        
        while(!process.empty()) {
            int cur = process.front();
            process.pop();
            res.push_back(cur);
            for(auto chd : child[cur]) process.push(chd);
        }
        return res;
    }
};