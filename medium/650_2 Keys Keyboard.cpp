class Solution {
public:
    int minSteps(int n) {
        // recursive & math
        // time complexixy: O(logn) ~ O(n), space complexity: O(1) + stack memory
        // 4ms, beats 91.28%
        
        // Main idea:
        // Notice only can copy all existed value
        // And use division is always faster or equal than one by one.
        // So simply find all divisors and branch into subproblems.
        if(n == 1) { return 0; }
        for(int i = 2; i < n; i++) {
            if(n % i == 0) { return i + minSteps(n / i); }      // Divisor i needs i more times
        }
        return n;
    }
};