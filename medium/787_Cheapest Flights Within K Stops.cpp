class Solution {
public:
    typedef tuple<int, int, int> ti;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Graph
        
        // method 1:
        // Bellman ford
        // time complexity: O(VE), space complexity: O(n)
        // 12ms, beats 97.14% | 11MB, beats 100%
        
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i <= K; ++i) {
            vector<int> tmp(dist);
            for(const auto& f : flights) {
                tmp[f[1]] = min(tmp[f[1]], dist[f[0]] + f[2]);
            }
            dist = tmp;
        }
        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};

// method 2
// Dijkstra based
// time complexity: should bigger than O(E + VlogV), space complexity: O(V+E)
// 28ms, beats 47.22%
class Solution {
public:
    typedef tuple<int, int, int> ti;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> cities(n, vector<pair<int, int>>());
        for(const auto& f : flights) cities[f[0]].push_back({f[1], f[2]});
        
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.emplace(0, src, K + 1);  // Note the usage and format of emplace!
        while(!pq.empty()) {
            auto [cost, cur, stops] = pq.top(); pq.pop();
            if(cur == dst) return cost;
            if(stops == 0) continue;
            for(auto& c : cities[cur]) {
                pq.emplace(cost + c.second, c.first, stops - 1);
            }
        }
        return -1;
    }
};

// method 3
// DFS with pruning
// 40ms, beats 37.45%
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> cities(n, vector<pair<int, int>>());
        vector<bool> visited(n, false);
        for(const auto& f : flights) {
            cities[f[0]].push_back({f[1], f[2]});
        }
        
        int res = INT_MAX;
        visited[src] = true; 
        dfs(cities, visited, dst, K, res, src, 0, 0);
        return res == INT_MAX ? -1 : res;
    }
    
    void dfs(vector<vector<pair<int, int>>>& cities, vector<bool>& visited,
                       int dst, int K, int& res, int cur, int stops, int cost) {
        if(cur == dst) {
            res = min(res, cost);
            return;
        }
        if(stops > K) return;
        
        for(const auto& p : cities[cur]) {
            if(!visited[p.first]) {
                if (cost + p.second > res) continue;    // IMPORTANT!!! prunning 
                visited[p.first] = true; 
                dfs(cities, visited, dst, K, res, p.first, stops + 1, cost + p.second);
                visited[p.first] = false; 
            }
        }
    }
};
