class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // union find
        // time complexity: O(n^2), space complexity: O(n)
        // 12ms, beats 98.93%
        
        // Main idea:
        // If edges.size() != n - 1, directly return false;
        // Use union find to check whether two node has same parent, if so, exists circle

        if(edges.size() != n - 1) { return false; }     // If size < n - 1, then must be disconnected, if size > n - 1, then must exist circle
        vector<int> parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for(auto edge : edges) {
            int f = edge[0], s = edge[1];
            // while(f != parent[f]) { f = parent[f]; }
            // while(s != parent[s]) { s = parent[s]; }
            f = find(parent, f);
            s = find(parent, s);
            if(s == f) { return false; }    // Two nodes are already connected, existed circle
            parent[f] = s;                  // Connect two nodes
        }
        return true;
    }
    
    // another helper function
    int find(vector<int>& parent, int p) {
        if(p != parent[p]) {
            parent[p] = find(parent, parent[p]);
        }
        return parent[p];
    }
};