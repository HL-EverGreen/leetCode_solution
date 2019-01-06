class Solution {
public:
    bool isMatch(string s, string p) {
        // dynamic programming
        // time complexity: O(mn), space complexity: O(mn)
        // 4ms, beats 99.9%
        
        // match[i][j] means if s.substr(0, i) matches p.substr(0, j)
        // assume * will not be the first character in p
        // if p[j - 1] != '*', match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.')
        // if p[j - 1] == '*', match[i][j - 2] (* repeat 0 time) or match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.') (* repeat at least 1 time)
        int m = s.length(), n = p.length();
        vector<vector<bool>> match(m + 1, vector<bool>(n + 1, false));
        match[0][0] = true;
        
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] == '*') {
                    match[i][j] = (j > 1 && match[i][j - 2] || (i > 0 && match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')));
                } else {
                    match[i][j] = (i > 0 && match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }
        return match[m][n];
    }
};