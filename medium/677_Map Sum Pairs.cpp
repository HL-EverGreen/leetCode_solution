class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        // map
        // insert time complexity: O(logn)
        // sum time complexity: O(n)
        // 0ms, beats 100%
        
        // Main idea:
        // Also can use Trie.
        // This method use ordered_map, can use lower_bound to find the start,
        // and .substr(0, n) != prefix to find the end.
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0, n = prefix.size();
        for(auto iter = m.lower_bound(prefix); iter != m.end() && iter->first.substr(0, n) == prefix; iter++) {
            sum += iter->second;
        }
        return sum;
    }
private:
    map<string, int> m;
};


/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */