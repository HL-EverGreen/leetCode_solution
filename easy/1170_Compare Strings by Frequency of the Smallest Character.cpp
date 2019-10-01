class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        // string
        // time complexity: O(m + n), space complexity: O(1)
        // 16ms, beats 97.75%
        
        // Main idea:
        // Loop all words and get their freq. Loop the result and calculate number of freq >= current index.
        // Loop all queries and get result.
        
        vector<int> tf(12, 0);
        for(auto& word : words) tf[getF(word)]++;
        for(int i = 9; i >= 0; --i) tf[i] += tf[i + 1]; // tf[i] presends number of words that f(word) >= i
        
        vector<int> res;
        for(auto& query : queries) {
            res.push_back(tf[getF(query) + 1]);
        }
        return res;
    }
    
    /* Calculate F for a given string */
    int getF(string& s) {
        vector<int> res(26, 0);
        for(auto& ch : s) res[ch - 'a']++;
        for(int i = 0; i < 26; ++i) if(res[i] > 0) return res[i];
        return 0;
    }
};