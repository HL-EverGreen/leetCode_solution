class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        // union find
        // space complexity: O(mn)
        // 100ms, beats 100%
        
        // main idea:
        // use union find to determine different points' common ancestor, if they have common ancestor, then they belong to the same island
        vector<int> roots(m * n, -1), res;
        int dir[5] = {1, 0, -1, 0, 1}, island = 0;
        for(auto pos : positions) {
            int x = pos.first, y = pos.second, idx_cur = x * n + y;
            roots[idx_cur] = idx_cur;
            island++;
            for(int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny = y + dir[i + 1], idx_new = nx * n + ny;
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || roots[idx_new] == -1) continue;
                int root_cur = findRoot(roots, idx_cur), root_new = findRoot(roots, idx_new);
                if(root_cur != root_new) {                       // if belong to different island, merge it and update union find table
                    roots[root_cur] = root_new;
                    island--;
                }
            }
            res.push_back(island);
        }
        return res;
    }
    
    int findRoot(vector<int>& roots, int idx) {
        // while(roots[idx] != idx) {
        //     idx = roots[idx] = roots[roots[idx]];
        // }
        if(roots[idx] != idx) roots[idx] = findRoot(roots, roots[idx]);
        return roots[idx];
    }
};