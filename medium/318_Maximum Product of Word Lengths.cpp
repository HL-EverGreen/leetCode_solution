class Solution {
public:
    int maxProduct(vector<string>& words) {
        // string pattern & bit manipulation
        // time complexity: O(n * max(m, n)), m is the length of word, space complexity: O(n)
        // 44ms, beats 92.19%
        
        // Main idea:
        // Still n^2 comparison between each word, but compare with bit pattern:
        //   1) Use bit 1 in corresponding position to represent characters in string.
        //   2) And use bit & operation to test whether exist common characters.
        
        int n = words.size();
        int res = 0;
        vector<int> masks(n);
        
        for(int i = 0; i < n; ++i) {
            string word = words[i];
            int mask = 0;
            // Generate bit pattern
            for(int j = 0; j < word.length(); ++j) mask |= (1 << (word[j] - 'a'));
            for(int j = 0; j < i; ++j) {
                // No common characters
                if((masks[j] & mask) == 0) res = max(res, int(words[j].length() * word.length()));
            }
            // Add pattern of current word
            masks[i] = mask;
        }
        return res;
    }
};
