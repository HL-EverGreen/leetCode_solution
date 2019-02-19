class Solution {
public:
    bool isMatch(string s, string p) {
        // string & DFS
        // 28ms, beast 100%
        
        return dfs(s, p, 0, 0) > 1;
    }
    
    // return value:
    // 0: reach the end of s but unmatched
    // 1: unmatched without reaching the end of s
    // 2: matched
    int dfs(string& s, string& p, int si, int pi) {
        if(si == s.length() && pi == p.length()) return 2;
        if(si == s.length() && p[pi] != '*') return 0;
        if(pi == p.length()) return 1;
        if(p[pi] == '*') {
            while(pi < p.length() - 1 && p[pi + 1] == '*') pi++;        // skip duplicate '*'
            for(int i = 0; i <= s.length() - si; i++) {                 // start 0 because '*' may stand for nothing
                int ret = dfs(s, p, si + i, pi + 1);
                if(ret == 0 || ret == 2) return ret;
            }
        }
        else if(p[pi] == '?' || p[pi] == s[si]) 
            return dfs(s, p, si + 1, pi + 1);
        return 1;
    }
};