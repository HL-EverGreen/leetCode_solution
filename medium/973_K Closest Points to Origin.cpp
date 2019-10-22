class Solution {
public:
    typedef pair<long, int> pii;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // priority queue & quick sort
        
        // Method1: priority queue
        // time complexity: O(NlogK), space complexity: O(K)
        // 236ms, beats 72.69%
        
        // Main idea:
        // Straight forward, use priority queue to store closest K points.        
        priority_queue<pii> pq;
        vector<vector<int>> res;
        int N = points.size();
        
        // Maintain K size priority queue
        for(int i = 0; i < N; ++i) {
            pq.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            if(i >= K) pq.pop();
        }
        while(!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
        

        // Method 2: Use native quick selection sout
        // time complexity: O(NlogK), space complexity: O(1)
        // 204ms, beats 95.27%
        nth_element(points.begin(), points.begin() + K - 1, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};