class Solution {
public:
    int flipLights(int n, int m) {
    	// math
    	// time complexity: O(1), space complexity: O(1)
    	// 0ms, beats 100%

    	// Main idea:
    	// Each n >= 3 or m >= 3 can be converted into n < 3 and m < 3
        if (m == 0 || n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return m == 1? 3:4;
        if (m == 1) return 4;
        return m == 2? 7:8;
    }
};