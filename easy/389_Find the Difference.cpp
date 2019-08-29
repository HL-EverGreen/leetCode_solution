class Solution {
public:
    char findTheDifference(string s, string t) {
        // array & bit manipulation
        // time complexity: O(n), space complexity: O(n) -> O(1)
        // 0ms, beats 100%
        
        // method 1: use hash table
        // unordered_map<char, int> dict;
        // for(auto ch : s) ++dict[ch];
        // for(auto ch : t) {
        //     if(--dict[ch] < 0) return ch;
        // }
        // return '/';
        
        // method 2: use XOR
        char c = 0;
        for(auto ch : s) c ^= ch;
        for(auto ch : t) c ^= ch;
        return c;
    }
};