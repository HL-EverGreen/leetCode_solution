class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // string & sliding window
        // time complexity: O(n), space complexity: O(n)
        // 36ms, beats 90.96%
        
        // main idea:
        // Record p's pattern, slide window along s, compare substring's pattern with p's pattern
        vector<int> s_dic(26, 0), p_dic(26, 0), res;
        int sSize = s.length(), pSize = p.length();
        if(sSize < pSize) return res;
        for(int i = 0; i < pSize; i++) {
            s_dic[s[i] - 'a']++;
            p_dic[p[i] - 'a']++;
        }
        if(s_dic == p_dic) res.push_back(0);
        for(int i = pSize; i < sSize; i++) {
            s_dic[s[i] - 'a']++;
            s_dic[s[i - pSize] - 'a']--;
            if(s_dic == p_dic) res.push_back(i - pSize + 1);
        }
        return res;
    }
};