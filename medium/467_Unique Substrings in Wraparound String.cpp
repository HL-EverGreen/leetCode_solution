class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // array & DP
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.11%
        
        // Main idea:
        // Use maxLen to record length of longest char-continuous subarray ends with current char
        // Since there might be duplicate substrings, so each time update the maxLen, we use maxLen[cur] = max(maxLen[cur], ++len);
        // The result is the sum of all values in `maxLen`
        
        if(p.empty()) return 0;
        
        vector<int> maxLen(26, 0);      // Length of longest char-continuous subarray ends with 'a' ~ 'z'
        maxLen[p[0] - 'a'] = 1;         // The first char
        int len = 1;
        int n = p.length();
        
        for(int i = 1; i < n; ++i) {
            int cur = p[i] - 'a';
            if((cur + 25) % 26 != p[i - 1] - 'a') len = 0;  // Compare with previous char
            maxLen[cur] = max(maxLen[cur], ++len);          // Keep the largest value
        }
        
        return accumulate(maxLen.begin(), maxLen.end(), 0);
    }
};
