class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        // string & pattern
        // time complexity: O(n), (n is the total characters)
        // space complexity: O(1)
        // 12ms, beats 95.02%
        
        // Main idea:
        // Compare two string at one time, and keep the result and continue
        // comparing with next one.
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        
        for(auto str : A) {
            vector<int> cntNew(26, 0);
            /* Record new string's pattern */
            for(auto ch : str) {
                cntNew[ch - 'a']++;
            }
            /* Compare and keep the smaller one */
            for(int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i], cntNew[i]);
            }
        }
        
        /* Flush to result */
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < cnt[i]; j++) {
                res.push_back(string(1, 'a' + i));
            }
        }
        return res;
    }
};