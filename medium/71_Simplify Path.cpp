class Solution {
public:
    string simplifyPath(string path) {
        // string
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 100%
        
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss, tmp, '/')) {
            if(tmp == "" || tmp == ".") continue;
            if(tmp == ".." && !stk.empty()) stk.pop_back();
            else if(tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/" + str;
        return res.empty() ? "/" : res;
    }
};