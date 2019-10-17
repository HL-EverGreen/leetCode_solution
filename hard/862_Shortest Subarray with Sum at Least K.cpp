class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        // deque
        // time complexity: O(n), space complexity: O(n)
        // 136ms, beats 89.36%
        
        // Main idea:
        // Simple sliding window won't work as it contains negative value.
        // Use deque to keep its status.
        
        int N = A.size(), res = N + 1;
        deque<int> d;
        vector<int> sum(N + 1, 0);
        for(int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];  // Sum of all elements from start to A[i - 1]
        
        for(int i = 0; i < N + 1; ++i) {
            while(d.size() > 0 && sum[i] - sum[d.front()] >= K) { // Origin simple sliding window
                res = min(res, i - d.front());
                d.pop_front();
            }
            while(d.size() > 0 && sum[i] <= sum[d.back()]) d.pop_back();    // **Remove negative value actually.**
                                                                            // More detailed on this, we always add at the LAST position
                                                                            // B[d.back] <- B[i] <- ... <- B[future id]
                                                                            // B[future id] - B[d.back()] >= k && B[d.back()] >= B[i]
                                                                            // B[future id] - B[i] >= k too
            d.push_back(i);
        }
        return res == N + 1 ? -1 : res;
    }
};