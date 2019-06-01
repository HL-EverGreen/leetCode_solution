class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // array & priority_queue
        // time complexity: O(nlogn), space complexity: O(n)
        // 0ms, beats 100%
        
        // Main idea:
        // Intuitive priority queue
        // Priority queue creation time complexity: O(n)
        // Priority queue insertion time complexity: O(logn)
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1) {
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            if(t1 > t2) { pq.push(t1 - t2); }
        }
        return pq.size() ? pq.top() : 0;
    }
};