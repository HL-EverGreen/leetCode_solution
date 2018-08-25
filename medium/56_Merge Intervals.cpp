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
    vector<Interval> merge(vector<Interval>& intervals) {//sort object vector
        int i_size=intervals.size();
        if(i_size<=1) return intervals;
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){return a.start<b.start;}); //can't #return a.start<=b.start#
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<i_size;i++){
            if(intervals[i].start>res.back().end) res.push_back(intervals[i]);
            else res.back().end=max(intervals[i].end,res.back().end);
        }
        return res;
    }
};
