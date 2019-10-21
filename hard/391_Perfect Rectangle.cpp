class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // geometry
        // time complexity: O(n), space complexity: O(n)
        // 80ms, beats 99.41%
        
        // Main idea:
        // The right answer must satisfy two conditions:
        //   1) The large rectangle area should be equal to the sum of small rectangles
        //   2) Count of all the points should be even, except the four corner points which should be one
        
        unordered_set<ulong> points;
        long area = 0;
        
        int x1 = INT_MAX, y1 = INT_MAX, x2 = 0, y2 = 0;
        for(const auto& r : rectangles) {
            x1 = min(x1, r[0]); y1 = min(y1, r[1]);
            x2 = max(x2, r[2]); y2 = max(y2, r[3]);
            area += (r[2] - r[0]) * (r[3] - r[1]);
            
            ulong p1 = (((ulong)(unsigned)r[0]) << 32) | (unsigned)r[1]; // bottom-left
            ulong p2 = (((ulong)(unsigned)r[0]) << 32) | (unsigned)r[3]; // top-left
            ulong p3 = (((ulong)(unsigned)r[2]) << 32) | (unsigned)r[3]; // top-right
            ulong p4 = (((ulong)(unsigned)r[2]) << 32) | (unsigned)r[1]; // bottom-right
            if(!points.insert(p1).second) points.erase(p1);
            if(!points.insert(p2).second) points.erase(p2);
            if(!points.insert(p3).second) points.erase(p3);
            if(!points.insert(p4).second) points.erase(p4);
        }
        
        // Check condition 1
        if(!points.count((((ulong)(unsigned)x1) << 32) | (unsigned)y1) 
           || !points.count((((ulong)(unsigned)x1) << 32) | (unsigned)y2)
           || !points.count((((ulong)(unsigned)x2) << 32) | (unsigned)y1)
           || !points.count((((ulong)(unsigned)x2) << 32) | (unsigned)y2)
           || points.size() != 4) return false;
        
        // Check condition 2
        return (y2 - y1) * (x2 - x1) == area;
    }
};
