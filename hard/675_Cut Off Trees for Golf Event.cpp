class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        // sort & BFS
        // 160ms, beats 90%
        
        // main idea: find all trees need to be cut and sort them in order
        // use BFS to find shortest distance between two adjacent trees
        
        if(forest.empty() || forest[0].empty()) return 0;
        
        vector<vector<int>> tree;
        int row = forest.size(), col = forest[0].size(), res = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(forest[i][j] > 1) tree.push_back({forest[i][j], i, j});
            }
        }
        
        // compute each step
        sort(tree.begin(), tree.end());
        for(int i = 0, cur_row = 0, cur_col = 0; i < tree.size(); i++) {
            int step = nextStep(forest, cur_row, cur_col, tree[i][1], tree[i][2]);
            if(step == -1) return -1;
            res += step;
            cur_row = tree[i][1];
            cur_col = tree[i][2];
        }
        return res;
    }
    
    // BFS
    int nextStep(vector<vector<int>>& forest, int start_row, int start_col, int end_row, int end_col) {
        if(start_row == end_row && start_col == end_col) return 0;
        
        int m = forest.size(), n = forest[0].size();
        int dir[5] = {1, 0, -1, 0, 1};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> point;
        
        visited[start_row][start_col] = 1;
        point.push({start_row, start_col});
        int step = 0;
        
        while(!point.empty()) {
            int size = point.size();
            step++;
            for(int i = 0; i < size; i++) {
                int cur_row = point.front().first, cur_col = point.front().second;
                point.pop();
                for(int j = 0; j < 4; j++) {
                    int ne_row = cur_row + dir[j], ne_col = cur_col + dir[j + 1];
                    if(ne_row < 0 || ne_row >= m || ne_col < 0 || ne_col >= n || visited[ne_row][ne_col] == 1 || forest[ne_row][ne_col] == 0) continue;
                    if(ne_row == end_row && ne_col == end_col) return step;
                    visited[ne_row][ne_col] = 1;
                    point.push({ne_row, ne_col});
                }               
            }
        }
        return -1;
    }
};