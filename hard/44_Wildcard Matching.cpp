class Solution {
public:
    bool isMatch(string s, string p) {
        // string & DFS
        // 24ms, beats 97.36% 
        
        return dfs(s, p, 0, 0) > 1;
    }
    
    // return value:
    // 0: reach the end of s but unmatched
    // 1: unmatched without reaching the end of s
    // 2: matched
    int dfs(string& s, string& p, int si, int pi) {
        if (si == s.size() && pi == p.size()) return 2;
        if (si == s.size() && p[pi] != '*') return 0;
        if (pi == p.size()) return 1;
        if (p[pi] == '*') {
            if (pi + 1 < p.size() && p[pi + 1] == '*') 
                return dfs(s, p, si, pi + 1); // skip duplicate '*'
            for(int i = 0; i <= s.size() - si; ++i) {
                int ret = dfs(s, p, si + i, pi + 1);
                if (ret == 0 or ret == 2) return ret; 
            }
        }
        if (p[pi] == '?' || s[si] == p[pi])
            return dfs(s, p, si + 1, pi + 1);
        return 1;
    }
};