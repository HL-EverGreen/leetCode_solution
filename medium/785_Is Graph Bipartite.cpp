class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // DFS & BFS
        // time complexity: O(n(m + n)), space complexity: O(n), n is the number of nodes
        // 20ms, beats 97.78%
        
        // Main idea:
        // Color the graph with two colors.
        // Check if able to color without conflicts.
        int size = graph.size();
        vector<int> color(size);
        for(int i = 0; i < size; i++) {
            if(color[i] == 0 && !isValid(graph, color, 1, i)) { return false; }     // Check each node anyway if graph is disconnected
        }
        return true;
    }
    
    bool isValid(vector<vector<int>>& graph, vector<int>& color, int cur_color, int index) {
        if(color[index] != 0) { return color[index] == cur_color; }                 // If colored, check whether conflicts
        color[index] = cur_color;
        for(auto next : graph[index]) {
            if(!isValid(graph, color, -cur_color, next)) {
                return false;
            }
        }
        return true;
    }
};