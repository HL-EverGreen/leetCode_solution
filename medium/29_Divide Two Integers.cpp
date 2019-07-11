class Solution {
public:
    int divide(int dividend, int divisor) {
        // bit manipulation
        // time complexity: O(logn), space complexity: O(1)
        // 4ms, beats 85.45%
        
        // Main idea:
        // Use << 1 to repeat multiply tmp which initially = divisor,
        // and compare tmp with dividend.
        
        // Special case
        if (dividend == INT_MIN) {
            if(divisor == 1) return INT_MIN;
            if(divisor == -1) return INT_MAX;
        }
        
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        int res = 0;
        while(dvd >= dvs) {                 // Repeatly compare with left shift
            long tmp = dvs, m = 1;
            while(tmp << 1 <= dvd) {
                tmp <<= 1;
                m <<= 1;
            } 
            dvd -= tmp;
            res += m;
        }
        return res * sign;
    }
};
