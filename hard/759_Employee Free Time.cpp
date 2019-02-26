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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        // array
        // time complexity: O(n), n is the number of all Intervals; space complexity: O(n)
        // 80ms, beats 80.43%
        
        // main idea:
        // Same as n workers each has one Interval, find common relax time
        // Use map to record each timestamp's adding or minusing number of busy workers (add when interval.start, minus when interval.end)
        // Accumulate all number of workers changed number from begin, when this number == 0, there is no busy work, so everybody is free, set (this_timeStamp, 0)
        // When last.end == 0, means that everybody are free till now, and workers > 0, update last.end = this_timeStamp. Because end of free time detected
        
        vector<Interval> res;
        map<int, int> m;
        for(auto& vec : schedule) {             // 得到每一时刻人员变动情况（增加或减少多少工作人数）
            for(auto& inter : vec) {
                m[inter.start]++;
                m[inter.end]--;
            }
        }
        int workers = 0;
        for(auto& iter : m) {                   // 累计当前人员变动情况，如果等于零，则所有人都休息
            workers += iter.second;
            if(workers == 0) res.push_back(Interval(iter.first, 0));    // 发现休息开始时刻，先push，找到休息结束时刻再修改end值
            if(workers != 0 && !res.empty() && res.back().end == 0) res.back().end = iter.first;
        }
        if(!res.empty() && res.back().end == 0) res.pop_back();         // 只有休息开始时刻没有结束时刻，舍弃
        return res;
    }
};