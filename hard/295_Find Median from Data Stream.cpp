class MedianFinder {
public:
    /** initialize your data structure here. */
    // priority queue
    // addNum time complexity: O(logn), findMedian time complexity: O(1)
    MedianFinder() {
        
    }
    
    // dynamically manage small and large queue
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if(large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        else return (small.top() + large.top()) / 2.0;
    }
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */