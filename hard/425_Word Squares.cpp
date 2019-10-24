class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        // DFS & Trie
        // 84ms, beats 64.96%
        
        // Main idea:
        // Use `startWith` to record each word in its each prefix.
        // Do dfs and try place word one by one.
        // When place current word, should base on previous placed word,
        // that is, find the prefix and search next possible word in `startWith`.
        // ***Note: Can also do with Trie
        
        unordered_map<string, vector<string>> startWith;
        vector<string> square;
        vector<vector<string>> squares;
        int N = words[0].length();
        
        // Construct startWith
        for(const auto word : words) {
            for(int i = 0; i < word.length(); ++i) 
                startWith[word.substr(0, i)].push_back(word);
        }
        
        square.resize(N);
        dfs(squares, square, startWith, 0, N);
        return squares;
    }
    
    // Do DFS to place each word one by one
    void dfs(vector<vector<string>>& squares, vector<string>& square,
            unordered_map<string, vector<string>>& startWith, int depth, int N) {
        if(depth == N) {
            squares.push_back(square);
            return;
        }
        
        string prefix = "";
        for(int i = 0; i < depth; ++i) prefix.push_back(square[i][depth]);  // Get prefix
        for(auto& next : startWith[prefix]) {
            square[depth] = next;
            dfs(squares, square, startWith, depth + 1, N);
        }
    }
};