// design & hash table
// time complexity: set(): O(1), get(): log(n), n is the number of elements with given key
// 388ms, beats 84.3%

// Main idea:
// Use unordered_map<string, map<int, string>> to store <key, <ts, value>>.
// Since map is ordered, can find largest element less than `ts` in O(logn) time

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto p = db[key].upper_bound(timestamp);            // Find iterator points to timestamp larget than given timestamp
        if(p != db[key].begin()) return (--p)->second;
        else return "";                                     // Include no such key or no <= ts situation
    }
private:
    unordered_map<string, map<int, string>> db;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */