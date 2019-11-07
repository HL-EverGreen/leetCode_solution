class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // DFS
        // time complexity: O(mn), space complexity: O(mn)
        // 44ms, beats 92.92%
        
        // Main idea:
        // Do dfs started from four edges, and use 1 to present visiting flg for Pacific ocean,
        // and 2 to present visiting flg for Atlantic ocean. Each time set (visited |= flg).
        // Only current height >= prev height, could the search continue.
        // So if the visited[i][j] == 3, that means it can both flow to two oceans.
        
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<vector<int>> res;
        vector<vector<int>> visited;
        int M = matrix.size(), N = matrix[0].size();
        visited.resize(M, vector<int>(N, 0));
        
        // Search from left and right edge
        for(int i = 0; i < M; ++i) {
            dfs(matrix, res, visited, i, 0, 1, INT_MIN);      // Search from Pacific ocean
            dfs(matrix, res, visited, i, N - 1, 2, INT_MIN);  // Search from Atlantic ocean
        }
        
        // Search from top and bottom edge
        for(int i = 0; i < N; ++i) {
            dfs(matrix, res, visited, 0, i, 1, INT_MIN);      // Search from Pacific ocean
            dfs(matrix, res, visited, M - 1, i, 2, INT_MIN);  // Search from Atlantic ocean
        }
        return res;
    }
    
    // Do dfs on a point, if current point has been visited or height < previous height, stop search
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& res, 
             vector<vector<int>>& visited, int row, int col, int flg, int prev) {
        if(row < 0 || row >= matrix.size()|| col < 0 || col >= matrix[0].size()
          || matrix[row][col] < prev || (visited[row][col] & flg) == flg) return;
        visited[row][col] |= flg;
        if(visited[row][col] == 3) res.push_back({row, col});   // Both flg has been set
        dfs(matrix, res, visited, row + 1, col, visited[row][col], matrix[row][col]);
        dfs(matrix, res, visited, row - 1, col, visited[row][col], matrix[row][col]);
        dfs(matrix, res, visited, row, col + 1, visited[row][col], matrix[row][col]);
        dfs(matrix, res, visited, row, col - 1, visited[row][col], matrix[row][col]);
    }
};