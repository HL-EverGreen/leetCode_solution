class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        // string & pattern
        // time complexity: O(n(s+w)), n is the number of word in list, s and w is length of word
        // space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Use char in W to compare first, if not ok, try to determine
        // whether current char in S is extended (>=3).
        // If not, return false
        
        int res = 0;
        for(auto& word : words) {
            if(check(S, word)) ++res;
        }
        return res;
    }
    
    bool check(const string& s, const string& w) {
        int M = s.length(), N = w.length();
        int j = 0;
        for(int i = 0; i < M; ++i) {
            if(j < N && s[i] == w[j]) ++j;  // Compare using char in w first
            else if(i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
            else if(i > 0 && i < M - 1 && s[i - 1] == s[i] && s[i] == s[i + 1]);
            else return false;
        }
        return j == N;
    }
};

