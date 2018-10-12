class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity) {} //hash table & list
    
    int get(int key) {
        auto iter = cache.find(key);
        if(iter == cache.end()) return -1;
        touch(iter);
        return iter->second.first;
    }
    
    void put(int key, int value) {
        auto iter = cache.find(key);
        if(iter != cache.end()) touch(iter);
        else{
            if(cache.size() == _capacity){
                cache.erase(used_list.back());
                used_list.pop_back();
            }
            used_list.push_front(key);
        }
        cache[key] = {value, used_list.begin()};
    }
    
private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> MIPII;
    
    LI used_list;
    MIPII cache;
    int _capacity;
    
    void touch(MIPII::iterator iter){
        int key = iter -> first;
        used_list.erase(iter->second.second);
        used_list.push_front(key);
        iter->second.second = used_list.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */