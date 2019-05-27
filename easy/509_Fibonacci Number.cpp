class Solution {
public:
    int fib(int N) {
        // recursive & iterative (DP)
        // time complexity: O(n), space complexity: O(n) (can be optimized to O(1))
        // 0ms, beats 100%
        
        // Main idea:
        // F(n) = F(n - 1) + F(n - 2)
        if(N < 2) { return N; }
        vector<int> cache(N + 1);
        cache[0] = 0, cache[1] = 1;
        for(int i = 2; i <= N; i++) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        return cache[N];
    }
};