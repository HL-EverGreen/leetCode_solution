class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        // array & intervals
        // time complexity: O(nlogn), space complexity: O(1)
        // 84ms, beats 94.44%
        
        // can also use cur_end = points[prev].second to present the critical edge
        if(points.empty()) return 0;
        auto comp = [](pair<int, int>& p1, pair<int, int>& p2) { return p1.first < p2.first; };
        sort(points.begin(), points.end(), comp);
        int res = 1, prev = 0;
        for(int i = 1; i < points.size(); i++) {
            if(points[i].first > points[prev].second) {
                res++;
                prev = i;
            } else if(points[i].second < points[prev].second) prev = i;     // same as update by min()
        }
        return res;
    }
};