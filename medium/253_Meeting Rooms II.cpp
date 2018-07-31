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
        
        //use vector&pair
        vector<pair<int,int>> vec;
        for(auto interval:intervals){
            vec.push_back(make_pair(interval.start,1));
            vec.push_back(make_pair(interval.end,-1));
        }
        sort(vec.begin(),vec.end());
        int room=0,sum=0;
        for(auto v:vec){
            sum+=v.second;
            room=max(room,sum);
        }
        return room;
    }
};