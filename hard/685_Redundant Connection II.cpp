class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // union find
        // time complexity: O(n^2), space complexity: O(n)
        // 8ms, beats 87.52%
        
        // First find whether exist a node be parents of two nodes.
        // If no nodes is parents of two nodes, then the problem is the same as I version.
        // And put them as candidates. Then ignore one of the candidate, and use union find like problem I version.
        
        /* Find duplicate parent node */
        int n = edges.size();
        vector<int> parent(n + 1, 0), canA, canB;
        for(auto& edge : edges) {
            if(parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                canA = {parent[edge[1]], edge[1]};
                canB = edge;
                edge[0] = 0;
            }
        }
        
        /* Union find */
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
        for(auto edge : edges) {
            int v1 = edge[0], v2 = edge[1];
            if(v1 == 0) { continue; }           // Ignore canB
            while(v1 != parent[v1]) { v1 = parent[v1]; }
            while(v2 != parent[v2]) { v2 = parent[v2]; }
            // v1 = find(parent, v1);
            // v2 = find(parent, v2);
            if(v1 == v2) { 
                if(canA.empty()) { return edge; }
                else return canA; 
            }
            parent[v2] = v1;
        }
        return canB;
    }
    
    // int find(vector<int>& p, int cur) {
    //     if(cur != p[cur]) {
    //         p[cur] = find(p, p[cur]);
    //     }
    //     return p[cur];
    // }
};