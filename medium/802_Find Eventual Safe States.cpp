// DFS & graph

// method 1
// DFS
// time complexity: O(n), space complexity: O(n)
// 152ms, beats 98.19%

// Use a little trick to avoid use new visited vector each time in the method 2 DFS
// Use color to state its status, if safe, then color = 2. if not visited, then color = 1.
// So color == 1 means in cycle.
class Solution {
public:
    //Find cycle for each node
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N, 0);
        vector<int> res;
        
        for(int node = 0; node < N; ++node) {
            if(color[node] == 1 || (color[node] == 0 && isCycle(node, graph, color))) continue;     // Has cycle
            res.push_back(node); //color is 2 (already done in DFS) or isCycle is false (no cycle)
        }
        return res;
    }
    
    //Color: 0 -- unvisited, 1 -- visited but not finish current path, 2 -- visited and done    
    bool isCycle(int node, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = 1;
        for(auto& adj: graph[node]) {
            if(color[adj] == 1) return true; // In cycle.
            if(color[adj] == 0 && isCycle(adj, graph, color)) return true;  // If child in cycle, then the parent too
        }
        color[node] = 2;    // Not in cycle
        return false;
    }
};


// method 2
// slow DFS
// time complexity: O(n), space complexity: O(n)
// 396ms, beats 12.13%

// Main idea:
// Only nodes in cycle that are not safe.
// So the problem is find nodes in cycle.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        unordered_set<int> visited;
        for(int i = 0; i < n; ++i) {
            if(dfs(graph, i, visited)) res.push_back(i);
        }
        return res;
    }
private:
    unordered_set<int> cycle_nodes; // Track nodes in cycle
    unordered_set<int> safe_nodes;  // Track nodes which are safe
    bool dfs(vector<vector<int>>& graph, int node, unordered_set<int> visited) {
        if(safe_nodes.count(node)) return true;
        if(cycle_nodes.count(node)) return false;
        
        if(visited.count(node)) {   // Has been visited in this dfs, so this node is in cycle
            cycle_nodes.emplace(node);
            return false;
        }
        
        visited.emplace(node);
        
        for(const int& next : graph[node]) {
            if(!dfs(graph, next, visited)) {
                cycle_nodes.emplace(node);      // If child nodes are cycle nodes, then the parent node too
                return false;
            }
        }
        
        safe_nodes.emplace(node);
        return true;
    }
};