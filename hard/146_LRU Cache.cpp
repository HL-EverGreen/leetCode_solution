class LRUCache {
public:
    // LRU & map & iterator
    // put complexity: O(n), get complexity: O(1)
    // 56ms, beats 98.48%
    
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()) touch(it);
        else {
            if(cache.size() == _capacity) {
                cache.erase(elem_list.back());
                elem_list.pop_back();
            }
            elem_list.push_front(key);
        }
        cache[key] = {value, elem_list.begin()};            // case of updating value
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> MIPII;
    
    LI elem_list;                                           // used to store all elements
    MIPII cache;                                            // cache
    int _capacity;                                          // capacity
    
    void touch(MIPII::iterator it) {                        // move the used one to the front of the element list, and update cache
        int key = it->first;
        elem_list.erase(it->second.second);
        elem_list.push_front(key);
        it->second.second = elem_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */