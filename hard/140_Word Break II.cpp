class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // string
        // DFS with memorization
        
        if(wordBreakPair.count(s)) return wordBreakPair[s];                                           // taken from memory
        vector<string> res;
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) res.push_back(s);             // a whole string is a word
        
        for(int i = 1; i < s.size(); i++) {                                                           // find all possible combinations
            string cur = s.substr(i);
            if(find(wordDict.begin(), wordDict.end(), cur) != wordDict.end()) {
                string rem = s.substr(0, i);
                vector<string> tempBreak = combine(cur, wordBreak(rem, wordDict));
                res.insert(res.end(), tempBreak.begin(), tempBreak.end());
            }
        }
        wordBreakPair[s] = res;
        return res;
    }
    
private:
    vector<string> combine(string word, vector<string> prev) {
        for(auto& p : prev) p += " " + word;
        return prev;
    }
    
    unordered_map<string, vector<string>> wordBreakPair;
    
    // memory limit exceed, but why? the method 1 can work but this can't
    // based on DP method
    /*
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int sSize = s.length();
        unordered_map<int, vector<string>> res;
        //vector<vector<string>> res(sSize + 1, vector<string>());
        res[0].push_back("");
        
        for(int i = 1; i <= sSize; i++) {
            for(int j = i - 1; j >= 0; j--) {
                string word = s.substr(j, i - j);
                if(!res[j].empty() && find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                    for(auto comb : res[j]) {
                        if(comb != "") res[i].push_back(comb + " " + word);
                        else res[i].push_back(word);
                    }
                }
            }
        }
        return res[sSize];
    }
    */
};