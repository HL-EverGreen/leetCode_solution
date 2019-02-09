class TrieNode {
public:
    TrieNode() {
        is_end = false;
        child = vector<TrieNode*>(26, NULL);
    }
    vector<TrieNode*> child;
    bool is_end;
};

class Trie {
public:
    TrieNode* getRoot() { return root; }
    Trie(vector<string>& words) {
        root = new TrieNode();
        for(auto word : words) addWord(word);
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++) {
            if(cur->child[word[i] - 'a'] == NULL) cur->child[word[i] - 'a'] = new TrieNode();
            cur = cur->child[word[i] - 'a'];
        }
        cur->is_end = true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // matrix & DFS & Trie
        // 56ms, beats 99%
        
        // Main idea:
        // Record words using trie data structure
        // For each start position of matrix, do DFS, if word is in words, pushback word
        unordered_set<string> res;
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                findWords(board, root, i, j, "", res);
            }
        }
        
        vector<string> finalRes(res.begin(), res.end());
        return finalRes;
    }
    
    // do DFS to each position of matrix
    void findWords(vector<vector<char>>& board, TrieNode* root, int x, int y, string word, unordered_set<string>& res) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') return;
        if(root->child[board[x][y] - 'a'] != NULL) {
            char c = board[x][y];
            word += c;
            board[x][y] = ' ';
            root = root->child[c - 'a'];
            if(root->is_end) res.insert(word);
            findWords(board, root, x + 1, y, word, res);
            findWords(board, root, x - 1, y, word, res);
            findWords(board, root, x, y + 1, word, res);
            findWords(board, root, x, y - 1, word, res);
            board[x][y] = c;
        }
    }
};