class Solution {
public:
    bool isSubsequence(string s, string t) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 60ms, beats 97.29%
        
        int si = 0, ti = 0, sSize = s.length(), tSize = t.length();
        while(si < sSize) {
            while(ti < tSize && t[ti] != s[si]) ti++;
            if(ti != tSize) {
                si++; ti++;
            }
            else return false;
        }
        return true;
        
        // another style
        /*
        int si = 0, ti = 0, sSize = s.length(), tSize = t.length();
        for(; ti < tSize; ti++) {
            if(t[ti] == s[si]) si++;
            if(si == sSize) return true;
        }
        return si == sSize;
        */
    }
};