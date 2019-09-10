class Solution {
public:
    string crackSafe(int n, int k) {
        // string & DFS
        // time complexity: O(k^n), space complexity: O(k^n) + stack memory
        // 8ms, beats 85.93%
        
        // And just use DFS to try every possibility
        // Each time visit a n-length password, next time visit password = current password.substr(1) + new_char in range(0, k)
        // The minimum length of total password is k^n + n - 1, when password reaches this length, stop and return

        // *Note: string.erase(pos, len), Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
        
        string cur = string(n, '0');
        string pwd = cur;
        unordered_set<string> used;
        int max_len = pow(k, n) + n - 1;
        
        used.insert(cur);
        if(findMinPwd(used, pwd, cur, max_len, k)) return pwd;
        else return "ERROR!"; // Can't reach here
    }
    
    /* Do dfs based on `cur` string, try every possible `next` string */
    bool findMinPwd(unordered_set<string>& used, string& pwd, string& cur, int max_len, int k) {
        if(pwd.length() == max_len) return true;
        string base = cur.substr(1);
        for(char ch = '0'; ch < k + '0'; ++ch) {
            string next = base + ch;     // Candidates

            if(used.count(next) == 0) {
                pwd.push_back(ch);
                used.insert(next);
                if(findMinPwd(used, pwd, next, max_len, k)) return true;
                used.erase(next);
                pwd.pop_back();
            }
        }
        return false;
    }
};