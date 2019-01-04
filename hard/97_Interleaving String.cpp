class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // dynamic programming
        // time complexity: O(mn), space complexity: O(mn)
        // 0ms, beats 100%
        
        // dp[i][j] represents if s3 is interleaving at (i+j)th position when s1 is at ith position, and s2 is at jth position.
        // 0th position means empty string.
        if(s1.length() + s2.length() != s3.length()) { return false; }
        bool isInterl[s1.length() + 1][s2.length() + 1] = {false};
        isInterl[0][0] = true;
        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                if(i == 0 && j > 0) {
                    isInterl[i][j] = (isInterl[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                } else if(i > 0 && j == 0) {
                    isInterl[i][j] = (isInterl[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                } else if(i > 0 && j > 0){
                    isInterl[i][j] = ((isInterl[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (isInterl[i][j - 1] && s2[j - 1] == s3[i + j - 1]));
                }
            }
        }
        return isInterl[s1.length()][s2.length()];
    }
};