class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // string
        // time complexity: O(mn), space complexity: O(1) -> O(26)
        // 4ms, beats 97.2%
        
        // Main idea:
        // Construct mapping from alien alphabet to normal alphabet and determine whether ordered
        
        int alienMap[26];
        for(int i = 0; i < 26; ++i) alienMap[order[i] - 'a'] = i;
        for(auto& word : words) {
            for(auto& c : word) c = 'a' + alienMap[c - 'a'];
        }
        return is_sorted(words.begin(), words.end());
    }
};