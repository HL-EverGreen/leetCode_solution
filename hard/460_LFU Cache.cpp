// Design & list & hashmap
// time complexity: O(1) for both get() and put()
// space complexity: O(n)
// 116ms, beats 85.39%

// Main idea:
// Use three maps, one to store key:<value,freq> pair, one store freq:list<key> and one store key:list::iterator.
// When get, delete key's iterator in current freq list, add freq and insert into new freq list.
// When put, if the key is already in it, modify value. If key is not here, use min_freq to find victim in the list.
//           And then add the new element with freq 1

class LFUCache {
public:
    LFUCache(int capacity) {
        min_freq = 0;
        size = capacity;
    }
    
    int get(int key) {
        if(!kv.count(key)) return -1;
        freq_list[kv[key].second].erase(k_iter[key]);   // Remove iterator in old list
        kv[key].second++;
        freq_list[kv[key].second].push_back(key);       // Add iterator in new list
        k_iter[key] = --freq_list[kv[key].second].end();
        if(freq_list[min_freq].empty()) ++min_freq;     // If current freq list is empty, add min_freq
        return kv[key].first;
    }
    
    void put(int key, int value) {
        if(size == 0) return;
        if(get(key) != -1) {        // Already in it
            kv[key].first = value;
            return;
        }
        
        if(kv.size() >= size) {     // Remove victim
            int victim = freq_list[min_freq].front();
            freq_list[min_freq].pop_front();
            kv.erase(victim);
            k_iter.erase(victim);
        }
        
        // Add new element
        kv[key] = {value, 1};
        min_freq = 1;
        freq_list[min_freq].push_back(key);
        k_iter[key] = --freq_list[min_freq].end();
    }
private:
    unordered_map<int, pair<int, int>> kv;
    unordered_map<int, list<int>> freq_list;
    unordered_map<int, list<int>::iterator> k_iter;
    int min_freq;
    int size;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */