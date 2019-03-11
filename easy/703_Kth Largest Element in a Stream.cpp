class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        // priority queue
        // time complexity: add: O(logk), space complexity: O(k)
        // 56ms, beats 73.74%
        
        size = k;
        for(auto& num : nums) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */