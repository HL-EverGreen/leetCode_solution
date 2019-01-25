class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // string & hash table
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.22%
        
        // Use a hash map for both s and t to record character's position
        if(s.length() != t.length()) return false;
        int sTable[128] = {0}, tTable[128] = {0};
        for(int i = 0; i < s.length(); i++) {
            if(sTable[s[i]] != tTable[t[i]]) return false;      
            sTable[s[i]] = tTable[t[i]] = i + 1;                // record current character's last occurence position
        }
        return true;
    }
};