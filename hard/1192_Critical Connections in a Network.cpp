class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // graph & DFS
        // time complexity: O(n), space complexity: O(n)
        // 740ms, beats 90.25%; 139.9MB, beats 100%
        
        // Main idea:
        // Use disc to record its original unique index according the DFS order.
        // And use low to record possible reachable lowest index (if there is at least two paths to it).
        // So if low[next] > disc[cur], the {cur, next} must be a critical connection.
        
        vector<bool> visited(n, false);
        vector<int> disc(n);
        vector<int> low(n);
        vector<int> parent(n, -1);
        vector<vector<int>> res;
        int cnt = 0;
        vector<vector<int>> conn(n, vector<int>());
        
        // Construct the connection vector
        for(auto& c : connections) {
            conn[c[0]].push_back(c[1]);
            conn[c[1]].push_back(c[0]);
        }
        
        dfs(conn, res, visited, disc, low, parent, 0, cnt);
        return res;
    }

private:
    /* Do dfs and adjust dics, low for each node. And detect critical connections */
    void dfs(vector<vector<int>>& conn, vector<vector<int>>& res, vector<bool>& visited,
             vector<int>& disc, vector<int>& low, vector<int>& parent, int cur, int& cnt) {
        visited[cur] = true;
        disc[cur] = low[cur] = cnt++;   // Set unique index
        for(auto& next : conn[cur]) {
            if(!visited[next]) {    // New node
                parent[next] = cur;
                dfs(conn, res, visited, disc, low, parent, next, cnt);
                low[cur] = min(low[cur], low[next]);    // Update possible low value
                if(low[next] > disc[cur]) res.push_back({cur, next}); // Low value is still larger than disc value, then there must be only
                                                                      // one path connectint cur and next, which is also a critical connection.
            } else if(next != parent[cur]) {    
                low[cur] = min(low[cur], disc[next]);
            }
        }
    }
};