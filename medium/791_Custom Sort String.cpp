class Solution {
public:
    string customSortString(string S, string T) {
        // string & pattern
        // time complexity: O(n^2logn), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Straight forward
        sort(T.begin(), T.end(), [S](char a, char b){
            return S.find(a) < S.find(b);
        });
        return T;
        
        /* Or use STL */
        // time complexity: O(nlogn), space complexity: O(1)
        /*
        unordered_map<char, int> dir;
        for (int i = 0; i < S.size(); i++) {
            dir[S[i]] = i + 1;
        }
        sort(T.begin(), T.end(),
             [&](char a, char b) { return dir[a] < dir[b]; });
        return T;
        */
    }
};