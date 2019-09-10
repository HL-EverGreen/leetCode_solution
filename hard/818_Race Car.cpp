class Solution {
public:
    int racecar(int target) {
        // DP
        // 0ms, beats 100%
        
        // Main idea:
        // https://leetcode.com/problems/race-car/discuss/123834/C%2B%2BJavaPython-DP-solution
        
        // n continous A can arrive at 2^n-1 position.
        // Let's say n is the length of target in binary and we have 2 ^ (n - 1) <= target < 2 ^ n
        // We have 2 strategies here:
        // 1) Go pass our target , stop and turn back. We take n instructions of A: 1 + 2 + 4 + ... + 2 ^ (n-1) = 2 ^ n - 1
        //    Then we turn back by one R instruction. In the end, we get closer by n + 1 instructions.
        // 2) Go as far as possible before pass target, stop and turn back
        //    We take N - 1 instruction of A and one R. Then we take m instructions of A, where m < n
        //    *Note: In here we take m instructions in opposite directions after only 1 R, since take 2 R and do
        //           m instructions in the same direction may cause redundant operations. 
        //           (like still occur RA in the following, so RR...RA is the same as RAR..., but spend one more operation)
        
        if(dp[target]) return dp[target];
        int n = floor(log2(target)) + 1;        // The length of binary presentation of target
        if((1 << n) == target + 1) dp[target] = n;
        else {
            dp[target] = racecar((1 << n) - target - 1) + n + 1;    // Exceed the target and come back. 1 is for 'R', n is for previous instructions
            for(int m = 0; m < n - 1; ++m) {    // Not exceed the target, do m instructions in opposite directions to remove possible redundancies
                dp[target] = min(dp[target], racecar(target - (1 << (n - 1)) + (1 << m)) + n + m + 1);
            }
        }
        return dp[target];
    }
private:
    int dp[10001];
};