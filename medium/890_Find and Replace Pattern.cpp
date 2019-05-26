class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // string pattern
        // time complexity: O(mn), space complexity: O(m)
        // 8ms, beats 74.78%
        
        // Main idea:
        // Use a formalization function to formalize every string before comparison
        vector<string> res;
        string f_pattern = formalizeString(pattern);
        
        /* Comparison */
        for(auto word : words) {
            if(formalizeString(word) == f_pattern) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    /* Formalization function */
    string formalizeString(string word) {
        unordered_map<char, int> dict;
        for(auto ch : word) {
            if(!dict.count(ch)) {
                dict[ch] = dict.size();
            }
        }
        for(auto& ch : word) {
            ch = 'a' + dict[ch];
        }
        return word;
    }
};