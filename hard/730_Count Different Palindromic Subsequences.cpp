class Solution {
public:
    int countPalindromicSubsequences(string S) {
        // DP
        // time complexity: O(N^2), space complexity: O(N^2)
        // 84ms, beats 71.06%
        
        // Main idea:
        // dp[i][j] presents number of different palindromes in substring S[i~j].
        // 1) If S[i] != S[j], the situation is simple:
        //      dp[start][end] = dp[start + 1][end] + dp[start][end - 1] - dp[start + 1][end - 1];
        // 2) If S[i] == S[j], see comments below.
        
        int N = S.length();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        for(int i = 0; i < N; ++i) dp[i][i] = 1;    // Initialize for single character string
        
        for(int dis = 1; dis < N; ++dis) {
            for(int start = 0; start + dis < N; ++start) {
                int end = start + dis;
                if(S[start] == S[end]) {
                    /* Variable low and high here are used to get rid of the duplicate*/
                    int low = start + 1, high = end - 1;
                    while(low <= high && S[low] != S[end]) ++low;   // Find same char
                    while(low <= high && S[high] != S[end]) --high;
                    if(low > high) {
                        // consider the string from i to j is "a...a", where there is no character 'a' inside the leftmost and rightmost 'a'
                       /* eg:  "aba" while i = 0 and j = 2:  dp[1][1] = 1 records the palindrome{"b"}, 
                         the reason why dp[i + 1][j  - 1] * 2 counted is that we count dp[i + 1][j - 1] one time as {"b"}, 
                         and additional time as {"aba"}. The reason why 2 counted is that we also count {"a", "aa"}. 
                         So totally dp[i][j] record the palindrome: {"a", "b", "aa", "aba"}. */
                        dp[start][end] = 2 * dp[start + 1][end - 1] + 2;
                    } else if(low < high) {
                         // consider the string from i to j is "a...a...a... a" where there are at least two character 'a' close to leftmost and rightmost 'a'
                       /* eg: "aacaa" while i = 0 and j = 4: the dp[i + 1][j - 1] records the palindrome {"a",  "c", "aa", "aca"}. 
                          the reason why dp[i + 1][j  - 1] * 2 counted is that we count dp[i + 1][j - 1] one time as {"a",  "c", "aa", "aca"}, 
                          and additional time as {"aaa",  "aca", "aaaa", "aacaa"}.  Now there is duplicate :  {"aca"}, 
                          which is removed by deduce dp[low + 1][high - 1]. So totally dp[i][j] record {"a",  "c", "aa", "aca", "aaa", "aaaa", "aacaa"}
                          */
                        dp[start][end] = 2 * dp[start + 1][end - 1] - dp[low + 1][high - 1];
                    } else {
                          // consider the string from i to j is "a...a...a" where there is only one character 'a' inside the leftmost and rightmost 'a'
                       /* eg:  "aaa" while i = 0 and j = 2: the dp[i + 1][j - 1] records the palindrome {"a"}.  
                         the reason why dp[i + 1][j  - 1] * 2 counted is that we count dp[i + 1][j - 1] one time as {"a"}, 
                         and additional time as {"aaa"}. the reason why 1 counted is that 
                         we also count {"aa"} that the first 'a' come from index i and the second come from index j. So totally dp[i][j] records {"a", "aa", "aaa"}
                        */
                        dp[start][end] = 2 * dp[start + 1][end - 1] + 1;
                    }   
                } else {    // S[start] != S[end]
                    dp[start][end] = dp[start + 1][end] + dp[start][end - 1]
                                   - dp[start + 1][end - 1];
                }
                dp[start][end] = dp[start][end] < 0 ? dp[start][end] + 1000000007 
                                                    : dp[start][end] % 1000000007;
            }
        }
        
        return dp[0][N - 1];
    }
};

