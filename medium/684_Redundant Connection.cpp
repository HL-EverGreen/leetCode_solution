class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // union find
        // time complexity: O(n^2), space complexity: O(2000)
        // 4ms, beats 99.11%
        
        // Use union find to group points which is connected.
        // If all two nodes have occurred before, finally will v1 == v2
        vector<int> p(2000);
        for(int i = 0; i < 2000; i++) {
            p[i] = i;
        }
        for(auto edge : edges) {
            int v1 = edge[0], v2 = edge[1];
            while(v1 != p[v1]) { v1 = p[v1]; }
            while(v2 != p[v2]) { v2 = p[v2]; }
            if(v1 == v2) { return edge; }
            p[v1] = v2;
        }
        return {};
    }
};