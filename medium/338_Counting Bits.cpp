class Solution {
public:
    vector<int> countBits(int num) {
        // bitwise manipulation & DP
        // time complexity: O(n), space complexity: O(n)
        // 64ms, beats 100%
        
        // main idea:
        // find relationship between two countBitOne[], here we use those two integers whose bit one diffs 1
        
        vector<int> countBitOne(num + 1, 0);
        for(int i = 1; i <= num; i++) countBitOne[i] = countBitOne[i & (i - 1)] + 1;
        // for(int i = 1; i <= num; i++) countBitOne[i] = countBitOne[i>>1] + (i & 1);
        return countBitOne;
    }
};