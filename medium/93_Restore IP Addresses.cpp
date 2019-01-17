class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // string & DFS
        // 0ms, beats 100%
        
        // each round dfs from start to start + 3
        vector<string> res;
        string ip;
        findIP(res, s, ip, 0, 0);
        return res;
    }
    
    void findIP(vector<string>& res, string s, string ip, int start, int step) {
        if(start == s.length() && step == 4) {
            ip.erase(ip.end() - 1);                     // remove the last '.' from the last decimal number
            res.push_back(ip);
            return;
        }
        
        if(s.size() - start > (4 - step) * 3) return;
        if(s.size() - start < 4 - step) return;
        int num = 0;
        for(int i = start; i < start + 3; i++) {
            num = num * 10 + (s[i] - '0');
            if(num <= 255) {
                ip += s[i];
                findIP(res, s, ip + '.', i + 1, step + 1);
            }
            if(num == 0) break;
        }
    }
};