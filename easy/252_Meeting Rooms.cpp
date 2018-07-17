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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()<=1) return true;
        sort(intervals.begin(),intervals.end(),[](Interval first,Interval second){return first.start<second.start;});//sort vector<struct>
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i].end>intervals[i+1].start)
                return false;
        }
        return true;
    }
};
