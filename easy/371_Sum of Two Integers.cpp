class Solution {
public:
    int getSum(int a, int b) {
        // bit manipulation
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Calculate carry mask each round, and left shift 1 for adding in next round
        while(b != 0) {
            unsigned int tmp = a & b;           // carry mask, note unsigned int here
                                                // since left shift of negative number is undefined behavior
            a = a ^ b;
            b = tmp << 1;
        }
        return a;
    }
};