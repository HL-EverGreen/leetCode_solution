class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // array & sort
        // time complexity: O(nlogn), space complexity: O(n)
        // 128ms, beats 92.02%
        
        vector<pair<double, int>> dis;
        vector<vector<int>> res;
        int cnt = 1;
        for(int i = 0; i < points.size(); i++) 
            dis.push_back(make_pair(pow(points[i][0], 2) + pow(points[i][1], 2), i));
        sort(dis.begin(), dis.end());

        res.push_back({points[dis[0].second][0], points[dis[0].second][1]});
        for(int i = 1; i < dis.size(); i++) {
            if(dis[i].first > dis[i - 1].first) cnt++;
            if(cnt > K) break;
            res.push_back({points[dis[i].second][0], points[dis[i].second][1]});
        }
        return res;
        
        // a super concise version, but seems not consider duplicate? Maybe not require to consider that...
        /*
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
        */
    }
};