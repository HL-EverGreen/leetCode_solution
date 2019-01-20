class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // string & hash table
        // time complexity: O(n), space complexity: O(n)
        // 24ms, beats 87.78%
        
        unordered_map<int, int> dict;
        int start = -1, len = 0;
        for(int i = 0; i < s.length(); i++) {
            if(dict.find(s[i]) != dict.end()) {
                start = max(start, dict[s[i]]);
            }
            dict[s[i]] = i;
            len = max(len, i - start);
        }
        return len;
    }
};