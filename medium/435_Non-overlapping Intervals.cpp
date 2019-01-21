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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        // array & intervals
        // time complexity: O(nlogn), space complexity: O(1)
        // 8ms, beats 98.15%
        
        // update critical end value
        auto comp = [](Interval& a, Interval& b){ return a.start < b.start; };
        sort(intervals.begin(), intervals.end(), comp);

        int res = 0, prev = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start < intervals[prev].end) {
                res++;
                if(intervals[i].end < intervals[prev].end) prev = i;
            } else prev = i;
        }
        return res;
    }
};