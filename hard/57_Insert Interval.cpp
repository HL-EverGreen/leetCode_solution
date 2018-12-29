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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 99.22%
        
        // divide into 3 steps: 
        // First, put all intervals that are to the left of the inserted interval.
        // Second, merge all intervals that intersect with the inserted interval.
        // Finally, put all intervals that are to the right of the inserted interval.
        int size = intervals.size(), index = 0;
        vector<Interval> res;
        
        while(index < size && intervals[index].end < newInterval.start) {
            res.push_back(intervals[index++]);    
        }
        
        while(index < size && intervals[index].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[index].start);
            newInterval.end = max(newInterval.end, intervals[index].end);
            index++;
        }
        res.push_back(newInterval);
        
        while(index < size) {
            res.push_back(intervals[index++]);
        }
        
        return res;
    }
};