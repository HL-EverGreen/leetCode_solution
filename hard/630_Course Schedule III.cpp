class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // intervals & greedy
        // time complexity: O(nlogn), space complexity: O(n)
        // 120ms, beats 100%
        
        auto comp = [](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; };
        sort(courses.begin(), courses.end(), comp);
        multiset<int> cls;
        int total_time = 0;
        
        for(auto c : courses) {
            if(total_time + c[0] <= c[1]) {                         // if we have time to take the course, then take it
                cls.insert(c[0]);
                total_time += c[0];
            } else if(!cls.empty() && *cls.rbegin() > c[0]) {       // if we don't have enough time, we switch out a longer course
                total_time = total_time - *cls.rbegin() + c[0];
                cls.erase(--cls.end());
                cls.insert(c[0]);
            } // if don't have time && no longer course taken, ignore it
        }
        return cls.size();
    }
};