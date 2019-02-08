class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // string & DP
        // time complexity: O(k * n^2), k is the number of words in dictionary, n is the s.length()
        // space complexity: O(n)
        // 0ms, beats 100%
        
        // existBreak[i] presents whether s.substr(0, i) is a word break
        int sSize = s.length();
        vector<bool> existBreak(sSize + 1, false);
        existBreak[0] = true;
        for(int i = 1; i <= sSize; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(existBreak[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    existBreak[i] = true;
                    break;
                } 
            }
        }
        return existBreak[sSize];
    }
};