// design & string
// 0ms, beats 100%

// main idea:
// Use hash set to store all exact word
// Use hash table to store and count the number of all neighbors for all word when building the dictionary
// e.g. store *pple, a*ple..., appl* for word apple
// For search, attempt to search in hash table for all neighbours fo the given word.
//    1) If any neighbour's count is 1, then the word can't be itself which stored in set.
//    2) If any neighbours's count is larger than 1, then return true (even the word itself exists in hash set, this word
//       can be modified to another word in the hash set, so it doesn't matter)

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        exact_words.insert(dict.begin(), dict.end());
        for(auto word : dict) {
            vector<string> cands = findNeighbors(word);
            for(auto cand : cands) ++neighbours[cand];
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int n = word.length();
        
        for(int i = 0; i < n; i++) {
            string cand = word.substr(0, i) + "*" + word.substr(i + 1);
            int cnt = neighbours[cand];
            if(cnt > 1 || (cnt == 1 && !exact_words.count(word))) return true;
        }
        return false;
    }
private:
    unordered_set<string> exact_words;
    unordered_map<string, int> neighbours;
    
    /* Find all neighbours of given word, like *pple, a*ple..., appl* for word apple */
    vector<string> findNeighbors(string s) {
        vector<string> cands;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            cands.emplace(cands.end(), s.substr(0, i) + "*" + s.substr(i + 1));
        }
        return cands;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */