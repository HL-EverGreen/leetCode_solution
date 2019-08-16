class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        // string parse
        // time complexity: O(n), space complexity: O(n)
        // 12ms, beats 98.66%
        
        unordered_map<string, int> count;
        for(auto& cd : cpdomains) {
            int pos = cd.find(" ");
            int cnt = stoi(cd.substr(0, pos));
            string s = cd.substr(pos + 1);
            count[s] += cnt;
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '.') {
                    count[s.substr(i + 1)] += cnt;
                }
            }
        }
        
        vector<string> res;
        for(auto c : count) {
            res.push_back(to_string(c.second) + " " + c.first);
        }
        return res;
    }
};