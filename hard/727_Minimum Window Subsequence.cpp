class Solution {
public:
    string minWindow(string S, string T) {
        // Greedy & dp

        // greedy
        // time complexity: O(mn), space complexity: O(1)
        // 16ms, beats 92.65%
        
        // Main idea:
        // When success match, j++
        // When j moves to the end, it means find a subsequence. We move back to the start, and calculate the length.
        // Then continue to match from head from (start + 1)
        // We return the substring with smallest length
        
        int m = S.length(), n = T.length();
        int start = -1, len = m + 1, i = 0, j = 0;
        while (i < m) {
            if (S[i] == T[j]) {
                if (++j == n) {     // Successfully find a match
                    int end = i + 1;
                    
                    // Find current match's start point
                    while (--j >= 0) {
                        while (S[i--] != T[j]);
                    }
                    i++; j++;
                    
                    // Compare with current length
                    if (end - i < len) {
                        len = end - i;
                        start = i;
                    }
                }
            }
            i++;
        }
        return start != -1 ? S.substr(start, len) : "";
        
        // dp
        // time complexity: O(mn), space complexity: O(mn)
        // 164ms, beats 33.54%
        
        // Main idea:
        // dp[i][j] presents for S[0~i-1] and T[0~j-1], the biggest start index of subsequence of S that contains T. (biggest start index, so minimum the length)
        // If S[i - 1] == T[j - 1], dp[i][j] = dp[i - 1][j - 1], can keep former's value
        // Else, dp[i][j] = dp[i - 1][j], since no match, ignore last char in S
        // Finally, we can check dp[~][m] to calculate length of valid subsequence and return shortest one
        
        int len_s = S.length(), len_t = T.length();
        
        vector<vector<int>> dp(len_s + 1, vector<int>(len_t + 1, -1));
        for(int i = 0; i <= len_s; ++i) dp[i][0] = i;       // Since each substring of S contains "" (empty string)
        
        // Do DP
        for(int i = 1; i <= len_s; ++i) {
            for(int j = 1; j <= len_t; ++j) {
                if(S[i - 1] == T[j - 1]) dp[i][j] = dp[i - 1][j - 1];   // Can continue use former start index
                else dp[i][j] = dp[i - 1][j];         // Last char of S[0~i-1] doesn't match, so can ignore it.
            }
        }
        
        // Find largest start index to calculate result
        int start = -1, len = len_s + 1;
        for(int i = len_t; i <= len_s; ++i) {
            int idx = dp[i][len_t];
            if(idx != -1 && i - idx + 1 < len) {
                len = i - idx;  // len = (i - 1) - idx + 1 = i - idx
                start = idx;
            }
        }
        return start == -1 ? "" : S.substr(start, len);
    }
};