class Solution {
public:
    int findComplement(int num) {
        // Integer
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 88.5%
        
        // Main idea:
        // Use a mask to extract number's bit only
        unsigned int mask = ~0;
        while(mask & num) mask <<= 1;
        return ~mask & ~num;
    }
};