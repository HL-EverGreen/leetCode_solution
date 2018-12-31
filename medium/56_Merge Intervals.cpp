/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 99.40%
        
        if(intervals.empty()) { return intervals; }
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start; });
        
        res.push_back(intervals[0]);
        for(auto inter : intervals) {
            if(inter.start > res.back().end) {
                res.push_back(inter);
            } else {
                res.back().end = max(res.back().end, inter.end);
            }
        }
        return res;
    }
};