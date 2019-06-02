class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // string & pattern
        // time complexity: O(mn), space complexity: O(1)
        // 4ms, beats 87.84%
        
        // Main idea:
        // Give charcter in different row with different signs (first row with 001, second 010, third 100)
        // Make & operation to all characters in a word, determine if it == 0
        // If == 0, then contain characters from different set
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        vector<string> res;
        vector<int> dict(26);
        
        /* Make signs */
        for(int i = 0; i < 3; i++) {
            for(auto ch : rows[i]) { dict[ch - 'A'] = 1 << i; }
        }
        
        /* Determine whether contain characters from different set */
        for(auto word : words) {
            int tmp = 7;
            for(auto ch : word) {
                tmp &= dict[toupper(ch) - 'A'];
                if(tmp == 0) { break; }
            }
            if(tmp) { res.push_back(word); }
        }
        return res;
    }
};