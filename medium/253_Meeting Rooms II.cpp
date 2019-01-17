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
    int minMeetingRooms(vector<Interval>& intervals) {//map_or_vector
        // array
        // time complexity: O(nlogn), space complexity: O(n)
        // 12ms, beats 98.01%
        
        // sort all start and end timestamp, when meet start, + 1, meet end, -1
        int res = 0, cur = 0;
        vector<pair<int, int>> timeStamp;
        for(auto i : intervals) {
            timeStamp.push_back(make_pair(i.start, 1));
            timeStamp.push_back(make_pair(i.end, -1));
        }
        sort(timeStamp.begin(), timeStamp.end());
        for(auto t : timeStamp) {
            cur += t.second;
            res = max(res, cur);
        }
        return res;

        //use map
        //map sort the element automatically(except for unordered_map)
        /*
        map<int,int> mp;
        for(auto interval:intervals){
            mp[interval.start]+=1;
            mp[interval.end]-=1;
        }
        int room=0,sum=0;
        for(auto m:mp){
            sum+=m.second;
            room=max(room,sum); // need for rooms at every time stamp
        }
        return room;
        */
    }
};