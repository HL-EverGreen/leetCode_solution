class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // DFS
        // 84ms, beats 22.52%
        
        // Use visited to record visited node. Do normal DFS from the begining node
        
        // Actually can be far more neat and simple
        
        set<vector<int>> visited;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        return helper(maze, start, destination, visited, dirs);
    }
    
    bool helper(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, set<vector<int>>& visited, vector<vector<int>>& dirs) {
        if(visited.find(start) != visited.end()) return false;
        visited.insert(start);
        for(int i = 0; i < 4; i++) {
            vector<int> res = go2End(maze, start, dirs[i]);
            if(res == destination || helper(maze, res, destination, visited, dirs)) return true;
        }
        return false;
    }
    
    // find stop node
    vector<int> go2End(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir) {
        int i = start[0], j = start[1], m = maze.size(), n = maze[0].size();
        while(i >= 0 && i < m && j >= 0 && j < n && !maze[i][j]) {
            i += dir[0];
            j += dir[1];
        }
        return {i - dir[0], j - dir[1]};
    }
};