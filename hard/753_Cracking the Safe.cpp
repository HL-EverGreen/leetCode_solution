class Solution {
public:
    string crackSafe(int n, int k) {
        // string & DFS
        // 8ms, beats 94.37%
        
        // Each time visit a n-length password, next time visit password = current password.substr(1) + new_char in range(0, k)
        // The minimum length of total password is k^n + n - 1, when password reaches this length, stop and return

        // string.erase(pos, len), Erases the portion of the string value that begins at the character position pos and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.
        string pwd = "", cur = "";
        for(int i = 0; i < n; i++) { cur += '0';  pwd = cur; }
        int max_num = pow(k, n) + n - 1;
        unordered_set<string> visited;
        visited.insert(cur);
        if(findMinPwd(visited, pwd, cur, max_num, n, k)) { return pwd; }
        else return "ERROR!";
    }
    
    bool findMinPwd(unordered_set<string>& visited, string& pwd, string& cur, int max_num, int n, int k) {
        if(pwd.length() == max_num) { return true; }
        string next = cur.substr(1);
        for(char ch = '0'; ch < '0' + k; ch++) {
            next += ch;
            if(visited.find(next) == visited.end()) {
                pwd += ch;
                visited.insert(next);
                if(findMinPwd(visited, pwd, next, max_num, n, k)) { return true; }
                visited.erase(next);
                pwd = pwd.erase(pwd.length() - 1);
            }
            next = next.erase(next.length() - 1);
        }
        return false;
    }
};