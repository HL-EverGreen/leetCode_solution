class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Graph & Dijkstra
        
        // method 1
        // Dijkstra
        // time complexity: O(logV + E), space complexity: O(V)
        // 80ms, beats 96.77%
        
        // Main idea:
        // Use priority queue to store next closet node with start node.
        // And after process that node, add to visited set to avoid visit again.

        unordered_map<int, vector<pair<int, int>>> m;
        vector<int> dist(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int res = 0, u, v, w;
        
        for(auto& time : times) {
            m[time[0]].push_back({time[1], time[2]});
        }
        
        pq.push({0, K});
        dist[K] = 0;
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            u = p.second;
            if(visited[u]) continue;
            for(auto& next : m[u]) {
                v = next.first; w = next.second;
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
            visited[u] = true;
        }
        res = *max_element(dist.begin() + 1, dist.end());
        return res == INT_MAX ? -1 : res;
        

        // method 2
        // BFS
        // 112ms, beats 47.75%

        // Main idea:
        // Use queue to record current length, and update length to smaller one dynamically
        // Very close to the Dijkstra Algorithm, just need to use priority queue instead of queue, and
        // using set to track visited node (since use priority queue, the visited node's distance won't be smaller)

        unordered_map<int, int> received_ts;
        unordered_map<int, vector<pair<int, int>>> m;
        queue<pair<int, int>> q;
        int res = 0;
        
        for(auto& time : times) {
            m[time[0]].push_back({time[1], time[2]});
        }
        
        q.push({K, 0});
        received_ts[K] = 0;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(auto& next : m[p.first]) {
                int dis = p.second + next.second;
                if(received_ts[next.first] > dis || received_ts[next.first] == 0) {
                    if(next.first != K) {
                        received_ts[next.first] = dis;
                        q.push({next.first, dis});
                    }
                }
            }
        }
        if(received_ts.size() != N) return -1;
        for(auto& m : received_ts) res = max(res, m.second);
        return res;
        

        // method 3
        // Bellman Ford
        // 964ms, beats 12.11%
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};