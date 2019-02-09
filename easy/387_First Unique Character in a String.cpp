class Solution {
public:
    int firstUniqChar(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 32ms, beats 93.33%
        
        // main idea: 
        // idx status: 0 -> i -> -1
        // if -1 then appear more than once
        
        if (s.size() == 0) return -1;
        if (s.size()== 1) return 0;
        
        vector<int> idx(26,0);
        for(int i = 0; i < s.size(); i++) {
            if(idx[s[i] - 'a'] > 0) 
                idx[s[i] - 'a'] = -1;                       // second instance
            else if(idx[s[i] - 'a'] == 0) 
                idx[s[i] - 'a'] = i + 1;                    // first instance
        }
        
        int minidx = INT_MAX;
        for(auto i : idx) {
            if ((i > 0) && (i < minidx)) minidx = i;
        }
        return (minidx == INT_MAX) ? -1 : minidx - 1;
        
        
        // though O(n) but much more slower
        // Note: Brute force's time complexity is also O(n), but need traverse twice
        /*
        unordered_map<int, pair<int, int>> count;
        for(int i = 0; i < s.length(); i++) {
            count[s[i]].first++;
            count[s[i]].second = i;
        }
        int res = s.length();
        for(auto c : count) {
            if(c.second.first == 1) res = min(res, c.second.second);
        }
        return res == s.length() ? -1 : res;
        */
    }
};