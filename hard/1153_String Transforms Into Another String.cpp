class Solution {
public:
    bool canConvert(string str1, string str2) {
        // string & graph
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 90.06%
        
        // Main idea:
        // If single char in str1 mapped to multiple char in str2, return false.
        // Else, since # distinct char in str1 is >= # distinct char in str2
        // So if # discinct char in str2 is 26 and str1 != str2, must exist cycle, return false
        if(str1 == str2) return true;
        unordered_map<char, char> m;
        for(int i = 0; i < str1.size(); ++i) {
            if(m.count(str1[i]) && m[str1[i]] != str2[i]) return false;
            m[str1[i]] = str2[i];
        }
        return unordered_set<char>(str2.begin(), str2.end()).size() < 26;
    }
};