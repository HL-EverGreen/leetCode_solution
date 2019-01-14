class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 98.24%
        
        // skip all '#' and char before '#'
        for(int i = S.size() - 1, j = T.size() - 1; ; i--, j--) {
            for(int b = 0; i >= 0 && (b || S[i] == '#'); i--) { b += (S[i] == '#' ? 1 : -1); }
            for(int b = 0; j >= 0 && (b || T[j] == '#'); j--) { b += (T[j] == '#' ? 1 : -1); }
            if(i < 0 || j < 0 || S[i] != T[j]) { return i == -1 && j == -1; }
        }
    }
};