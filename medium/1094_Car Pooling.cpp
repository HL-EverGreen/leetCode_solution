class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // array
        // time complexity: O(nlogn), space complexity: O(n)
        // 8ms, beats 93.45%
        
        // Main idea:
        // Like meeting room, start pos + n people, end pos - n people.
        // Determine whether at all position, capacity is large enough
        map<int, int> m;
        for(auto t : trips) {
            m[t[1]] += t[0];        // Start pos + t[0]
            m[t[2]] -= t[0];        // End pos - t[0]
        }
        
        for(auto pos : m) {
            capacity -= pos.second;                           // Capacity is current availble position
            if(capacity < 0) { return false; }
        }
        return true;
        
    }
};