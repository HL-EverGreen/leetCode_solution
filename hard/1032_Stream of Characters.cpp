// Trie
// time complexity: O(n) for query, n is the current query length
//                  O(m) for building Trie, since there m words
// space complexity: O(m)
// 276ms, beats 85.11%

// Main idea:
// Build Trie in reverse of each word.
// Keep each char in query and try match word from back to front

class StreamChecker {
public:
    class TrieNode {
    public:
        bool isWord;
        vector<TrieNode*> next;
        TrieNode() {
            isWord = false;
            next.resize(26, nullptr);
        }
    };
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        buildTrie(words);
    }
    
    bool query(char letter) {
        TrieNode* cur = root;
        last.push_back(letter);
        for(int i = last.length() - 1; i >= 0; --i) {   // Search from back to front
            if(!cur->next[last[i] - 'a']) return false;
            cur = cur->next[last[i] - 'a'];
            if(cur->isWord) return true;
        }
        return false;
    }
    
private:
    void buildTrie(vector<string>& words) {
        for(const auto& w : words) {
            TrieNode* cur = root;
            for(int i = w.length() - 1; i >= 0; --i) {     // Build Trie in reverse order
                char ch = w[i];
                if(!cur->next[ch - 'a']) {
                    cur->next[ch - 'a'] = new TrieNode();
                }
                cur = cur->next[ch - 'a'];
            }
            cur->isWord = true;
        }
    }
    
    TrieNode* root;
    string last;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */