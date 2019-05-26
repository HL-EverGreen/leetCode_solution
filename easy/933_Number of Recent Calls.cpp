class RecentCounter {
public:
    // design & queue
    // time complexity: ping: O(n)
    // space complexity: O(n)
    // 196ms, beats 94.96%
    
    // Since input is guaranteed to be ordered, so simply using queue instead of priority queue is enough.
    // Continually pop outdated elements.
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t - 3000) { q.pop(); }
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */