class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sliding window
        // time complexity: O(n), space complexity: O(n)
        // 28ms, beats 94.48%
        
        // typical sliding window problem
        vector<int> sv(26), pv(26);
        vector<int> res;
        int s_len = s.length(), p_len = p.length();
        
        for(auto ch : p) ++pv[ch - 'a'];
        
        for(int i = 0; i < s_len; ++i) {
            ++sv[s[i] - 'a'];
            if(i >= p_len) --sv[s[i - p_len] - 'a'];
            if(sv == pv) res.push_back(i - p_len + 1);      // the '==' time complexity is O(1) as both vector's size is constant
        }
        return res;
    }
};