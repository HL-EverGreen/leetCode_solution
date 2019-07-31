class Solution {
public:
    int mirrorReflection(int p, int q) {
        // Math
        // time complexity: O(logn), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Repeatedly divide p, q by 2 until at least of them is odd
        // p odd, q even, return 0
        // p odd, q odd, return 1
        // p even, q odd, return 2
        while(p % 2 == 0 && q % 2 == 0) {
            p >>= 1; q >>= 1;
        }
        return q % 2 + (p + 1) % 2;
    }
};