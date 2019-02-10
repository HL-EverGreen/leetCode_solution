class Solution {
public:
    int hammingDistance(int x, int y) {
        // bitwise manipulation
        // 4ms, beats 100%
        
        // main idea:
        // XOR first, then count number of 1
        int res = 0, n = x ^ y;
        while(n) {        
            res++;
            n &= n - 1;                     // eliminate one 1 at one time
            
            // normal way
            // res += n & 1;
            // n >>= 1;
        }
        return res;
    }
};