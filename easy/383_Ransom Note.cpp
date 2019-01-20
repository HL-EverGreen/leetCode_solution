class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 12ms, beats 95.29%
        
        int mag[26] = {0};
        for(auto ch : magazine) {
            mag[ch - 'a']++;
        }
        for(auto ch : ransomNote) {
            if(--mag[ch - 'a'] < 0) return false;
        }
        return true;
    }
};