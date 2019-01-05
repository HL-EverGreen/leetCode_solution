class Solution {
public:
    int minCut(string s) {
        // dynamic programming
        
        // method 1 (method 2 is faster)
        // time complexity: O(n^2), space complexity: O(n^2)
        // 8ms, beats 77.54%
        
        // is_palin[i][j]: whether string s[i]...s[j] is palindrome
        // min_cut[i]: minimum number of cut needed to divide string s[0]...s[i-1] into all palindrome words
        
        int size = s.length();
        if(size <= 1) { return 0; }
        bool is_palin[size][size] = {false};
        //fill_n(&is_palin[0][0], size * size, false);
        int min_cut[size + 1];
        for(int i = 0; i <= size; i++) { min_cut[i] = i - 1; }
        
        for(int i = 1; i < size; i++) {
            for(int j = i; j >= 0; j--) {
                if(s[i] == s[j] && (i - j < 2 || is_palin[j + 1][i - 1])) {
                    is_palin[j][i] = true;
                    min_cut[i + 1] = min(min_cut[i + 1], 1 + min_cut[j]);
                }
            }
        }
        return min_cut[size];
        
        
        // method 2
        // another DP solution only require O(n) space since it does not need is_palin table
        // time complexity: O(n^2), space complexity: O(n)
        // 4ms, beats 93.54%
        /*
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) { cut[i] = i-1; }
        for (int i = 0; i < n; i++) {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j] ; j++) // odd length palindrome
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);

            for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) // even length palindrome
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
        }
        return cut[n];
        */
    }
};