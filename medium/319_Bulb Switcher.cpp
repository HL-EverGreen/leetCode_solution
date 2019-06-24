class Solution {
public:
    int bulbSwitch(int n) {
        // math
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // n only will be toggled at the round of its factors.
        // So whether a bulb will be on only depends on number of its factors.
        // So this question is equal to find all perfect square number <= n
        int res = 0;
        for(int i = 1; i * i <= n; i++) {
            res++;
        }
        return res;
    }
};